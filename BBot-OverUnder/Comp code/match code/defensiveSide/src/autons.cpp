#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(12, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .3, .03, 6, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 250, 4000);
  chassis.set_turn_exit_conditions(1, 250, 1500);
  chassis.set_swing_exit_conditions(1, 300, 2000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void kansasAuton(){
  intakeMotor.setPosition(0, degrees);
  wingsPiston.set(true); 
  wait(100, msec);
  wingsPiston.set(false); 
  chassis.drive_distance(59);
  intakeMotor.spinToPosition(155, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.turn_to_angle(120);
  wingsPiston.set(true); 
  intakeMotor.spinToPosition(30, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.drive_distance(32);
  wingsPiston.set(false); 
  chassis.drive_distance(-12);
  chassis.turn_to_angle(275);
  chassis.drive_distance(25);
  intakeMotor.spinToPosition(155, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.turn_to_angle(150);
  chassis.drive_distance(51);
  chassis.turn_to_angle(395);
  intakeMotor.spinToPosition(30, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.drive_distance(14);
}
void defensiveAuton(){
  chassis.drive_distance(35);
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