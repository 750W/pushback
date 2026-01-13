#include "headers/autons.hpp"
#include "lemlib/api.hpp"
#include "headers/robot_config.hpp"


void progskills1()
{
    // set position to x:0, y:0, heading:0
    chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    chassis.turnToHeading(90, 100000);
}