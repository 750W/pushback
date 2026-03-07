#include "lemlib/chassis/chassis.hpp"
#include "pros/distance.hpp"

class LogOddMap {
    public:
        LogOddMap(int width, int height, float cell_size, float l_occ, float l_free);
        int width;
        int height;
        float cell_size;
        float l_occ;
        float l_free;
        std::vector<float> logodds;
        float& cell(int x, int y);
        void occ(int x, int y);
        void free(int x, int y);
};

class MonteCarloMapper {
    public:
        MonteCarloMapper(lemlib::Chassis& chassis, pros::Distance& front, pros::Distance& right, pros::Distance& left,
                   float front_offset, float left_offset, float right_offset, LogOddMap& map);
        lemlib::Chassis& chassis;
        pros::Distance& front;
        pros::Distance& right;
        pros::Distance& left;
        float front_offset;
        float left_offset;
        float right_offset;
        LogOddMap& map;
    protected:
        void update();
};

class MonteCarlo {
    public:
        MonteCarlo(lemlib::Chassis& chassis, pros::Distance& front, pros::Distance& right, pros::Distance& left,
                   float front_offset, float left_offset, float right_offset);
        lemlib::Chassis& chassis;
        pros::Distance& front;
        pros::Distance& right;
        pros::Distance& left;
        float front_offset;
        float left_offset;
        float right_offset;
};
