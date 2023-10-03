#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void offensiveAuton(){
  intakeMotor.spinFor(134, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.drive_distance(45);
  chassis.turn_to_angle(90);
  intakeMotor.spinFor(31, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.drive_distance(12);
  chassis.turn_to_angle(270);
  chassis.drive_distance(22.5);
  chassis.turn_to_angle(90);
  
}

void defensiveAuton(){
  intakeMotor.spinFor(134, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.drive_distance(45);
  chassis.turn_to_angle(270);
  intakeMotor.spinFor(31, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.drive_distance(12);
  chassis.turn_to_angle(180);
  chassis.drive_distance(12);
  chassis.turn_to_angle(270);
  chassis.drive_distance(45);
  
}


void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}