/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// driveLeftBack        motor         9               
// driveRightBack       motor         2               
// driveLeftFront       motor         10              
// driveRightFront      motor         1               
// Controller1          controller                    
// cataMotor2           motor         5               
// pneuPiston1          digital_out   A               
// pneuPiston2          digital_out   B               
// cataMotor1           motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void fwd(double distance, int speed){
  driveLeftBack.spinFor(distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveRightBack.spinFor(distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveLeftFront.spinFor(distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveRightFront.spinFor(distance, rotationUnits::rev, speed, velocityUnits::pct);
}
void rev(double distance, int speed){
  driveLeftBack.spinFor(-distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveRightBack.spinFor(-distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveLeftFront.spinFor(-distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveRightFront.spinFor(-distance, rotationUnits::rev, speed, velocityUnits::pct);
}
void tRight(double distance, int speed){
  driveLeftBack.spinFor(-distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveRightBack.spinFor(distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveLeftFront.spinFor(-distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveRightFront.spinFor(distance, rotationUnits::rev, speed, velocityUnits::pct);
}
void tLeft(double distance, int speed){
  driveLeftBack.spinFor(distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveRightBack.spinFor(-distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveLeftFront.spinFor(distance, rotationUnits::rev, speed, velocityUnits::pct, false);
  driveRightFront.spinFor(-distance, rotationUnits::rev, speed, velocityUnits::pct);
}
void pistonCmnd(bool val){
  pneuPiston1.set(val);
  pneuPiston2.set(val);
}
void cataRapid(int reps){
  for(int i=0; reps <= i; i++){
    cataMotor1.spinFor(-reps, rotationUnits::rev, 100, velocityUnits::pct);
    cataMotor2.spinFor(-reps, rotationUnits::rev, 100, velocityUnits::pct);
  }
}


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
//void arcadeDrive(){
// basically the way it works for explaining to others (AKA MICHAEL)--- motorYouWantToSpin.spin(direction, speed, velocity type)
// left back motor
// driveLeftBack.spin(forward, (Controller1.Axis3.value() + Controller1.Axis1.value()), percent);
// // right back motor
// driveRightBack.spin(forward, (Controller1.Axis3.value() - Controller1.Axis1.value()), percent);
// // left front motor
// driveLeftFront.spin(forward, (Controller1.Axis3.value() + Controller1.Axis1.value()), percent);
// // right front motor
// driveRightFront.spin(forward, (Controller1.Axis3.value() - Controller1.Axis1.value()), percent);
//}
void tankDrive(){
  driveLeftBack.spin(forward, Controller1.Axis3.value(), percent);
  driveLeftFront.spin(forward, Controller1.Axis3.value(), percent);
  driveRightBack.spin(forward, Controller1.Axis2.value(), percent);
  driveRightFront.spin(forward, Controller1.Axis2.value(), percent);
}
void cataControl(){
   if (Controller1.ButtonB.pressing()){
     cataMotor1.spin(reverse, 100, percent);
     cataMotor2.spin(reverse, 100, percent);
   } else {
     cataMotor1.stop(brakeType:: coast);
     cataMotor2.stop(brakeType:: coast);

   }
}

void flapsControlOn(){
  pneuPiston1.set(true); 
  pneuPiston2.set(true);
}
void flapsControlOff(){
  pneuPiston1.set(false); 
  pneuPiston2.set(false);
}
void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
// arcade drive code controls
// arcadeDrive();
//tank drive code controls 
    tankDrive();
// outake code controls
    cataControl();
// flaps code controls
    Controller1.ButtonB.pressed(flapsControlOn);
    Controller1.ButtonY.pressed(flapsControlOff);
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // Run the pre-autonomous function.
  pre_auton();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
