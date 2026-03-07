/**
 * 750W
 * Monte Carlo Localization implementation
 */

//   ^
//   |
//  +Y  +X --->
// NOTE: "angle" and "heading" arent the same
// When we say angle we usually mean the math conventions, so -clockwise with 0 facing +X
// When we say heading we usually mean the lemlib heading, so +clockwise with 0 facing +Y

#include "lemlib/chassis/mcl.hpp"
#include "pros/rtos.hpp"
#include <cmath>

// mm to inches conversion factor
constexpr float MM_TO_IN = 1.0f / 25.4f;

// max distance from sensor (mm)
constexpr int DIST_MAX = 9000;

constexpr float L_MAX = 4;

LogOddMap::LogOddMap(int width, int height, float cell_size, float l_occ, float l_free) :
    width(width), height(height), cell_size(cell_size), l_occ(l_occ), l_free(l_free)
{
    logodds = std::vector<float>(width * height, 0.0f);
}

float& LogOddMap::cell(int x, int y) {
    return logodds[x + y * width];
}

/// @brief Mark a cell as occupied.
void LogOddMap::occ(int x, int y) {
    cell(x, y) += l_occ;
    if (cell(x, y) > L_MAX) cell(x, y) = L_MAX;
}

/// @brief Mark a cell as free.
void LogOddMap::free(int x, int y) {
    cell(x, y) -= l_free;
    if (cell(x, y) < -L_MAX) cell(x, y) = -L_MAX;
}

/// Snap a world coordinate to a grid cell index.
static int toGrid(float pos, float cell_size) {
    return static_cast<int>(std::floor(pos / cell_size));
}

MonteCarloMapper::MonteCarloMapper(
    lemlib::Chassis& chassis,
    pros::Distance& front,
    pros::Distance& right,
    pros::Distance& left,
    float front_offset,
    float left_offset,
    float right_offset,
    LogOddMap& map) :
    chassis(chassis),
    front(front),
    right(right),
    left(left),
    front_offset(front_offset),
    left_offset(left_offset),
    right_offset(right_offset),
    map(map) {
    pros::Task([this] {
        while (true) {
            update();
            pros::delay(10);
        }
    });
}

/**
 * @brief Cast a ray from the sensor origin through the grid using DDA, marking cells as free/occupied.
 *
 * @param map        the log-odds grid
 * @param ox         ray origin x (in)
 * @param oy         ray origin y (in)
 * @param angle_rad  ray direction in radians (math convention)
 * @param dist       distance to endpoint (in)
 * @param hit        whether to mark the final cell as hit (occupied)
 */
static void castRay(LogOddMap& map, float ox, float oy, float angle_rad, float dist, bool hit) {
    float dx = std::cos(angle_rad);
    float dy = std::sin(angle_rad);

    // endpoint of the ray (the occupied hit)
    float ex = ox + dx * dist;
    float ey = oy + dy * dist;

    // convert origin and endpoint to grid coordinates
    int hit_gx = toGrid(ex, map.cell_size);
    int hit_gy = toGrid(ey, map.cell_size);

    // starting grid cell
    int gx = toGrid(ox, map.cell_size);
    int gy = toGrid(oy, map.cell_size);

    // DDA setup
    int stepX = (dx >= 0) ? 1 : -1;
    int stepY = (dy >= 0) ? 1 : -1;

    // distance along the ray to cross one full cell in X or Y
    float tDeltaX = (dx != 0.0f) ? std::fabs(map.cell_size / dx) : 1e30f;
    float tDeltaY = (dy != 0.0f) ? std::fabs(map.cell_size / dy) : 1e30f;

    // distance along ray from origin to the first X and Y cell boundary
    float cell_border_x = (stepX > 0) ? (gx + 1) * map.cell_size : gx * map.cell_size;
    float cell_border_y = (stepY > 0) ? (gy + 1) * map.cell_size : gy * map.cell_size;

    float tMaxX = (dx != 0.0f) ? (cell_border_x - ox) / dx : 1e30f;
    float tMaxY = (dy != 0.0f) ? (cell_border_y - oy) / dy : 1e30f;

    int maxSteps = static_cast<int>(dist / map.cell_size) + map.width + map.height;

    for (int i = 0; i < maxSteps; i++) {
        if (gx < 0 || gx >= map.width || gy < 0 || gy >= map.height) break;

        // if we've reached the endpoint cell
        if (gx == hit_gx && gy == hit_gy) {
            if (hit) {
                map.occ(gx, gy);
            } else {
                map.free(gx, gy);
            }
            break;
        }

        // otherwise this cell is free (ray passed through it)
        map.free(gx, gy);

        // advance to next cell boundary
        if (tMaxX < tMaxY) {
            gx += stepX;
            tMaxX += tDeltaX;
        } else {
            gy += stepY;
            tMaxY += tDeltaY;
        }
    }
}

/// @brief Update the map with the current sensor readings.
void MonteCarloMapper::update() {
    lemlib::Pose pose = chassis.getPose();

    float heading_deg = pose.theta;
    float heading_rad = heading_deg * (M_PI / 180.0f);

    // our heading is +clockwise with 0 facing +Y
    // but to use sin and cos we need to convert to -clockwise with 0 facing +X (math convention)
    float front_std_rad = (90.0f - heading_deg) * (M_PI / 180.0f);
    float right_std_rad = front_std_rad - (M_PI / 2.0f);
    float left_std_rad  = front_std_rad + (M_PI / 2.0f);

    float rx = pose.x;
    float ry = pose.y;

    // find sensor origins
    float front_ox = rx + front_offset * std::cos(front_std_rad);
    float front_oy = ry + front_offset * std::sin(front_std_rad);

    float right_ox = rx + right_offset * std::cos(right_std_rad);
    float right_oy = ry + right_offset * std::sin(right_std_rad);

    float left_ox = rx + left_offset * std::cos(left_std_rad);
    float left_oy = ry + left_offset * std::sin(left_std_rad);

    // read distances (mm), convert to inches
    std::int32_t front_mm = front.get();
    std::int32_t right_mm = right.get();
    std::int32_t left_mm  = left.get();

    // cast ray for each sensor
    // if ray is > dist_max we just mark the whole ray as free
    if (front_mm > 0) {
        float dist_in = static_cast<float>(std::min(front_mm, static_cast<std::int32_t>(DIST_MAX))) * MM_TO_IN;
        castRay(map, front_ox, front_oy, front_std_rad, dist_in, front_mm < DIST_MAX);
    }

    if (right_mm > 0) {
        float dist_in = static_cast<float>(std::min(right_mm, static_cast<std::int32_t>(DIST_MAX))) * MM_TO_IN;
        castRay(map, right_ox, right_oy, right_std_rad, dist_in, right_mm < DIST_MAX);
    }

    if (left_mm > 0) {
        float dist_in = static_cast<float>(std::min(left_mm, static_cast<std::int32_t>(DIST_MAX))) * MM_TO_IN;
        castRay(map, left_ox, left_oy, left_std_rad, dist_in, left_mm < DIST_MAX);
    }
}
