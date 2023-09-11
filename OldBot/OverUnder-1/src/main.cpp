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
// driveLeftBack        motor         1               
// driveRightBack       motor         2               
// driveLeftFront       motor         3               
// driveRightFront      motor         4               
// Controller1          controller                    
// intakeRoller         motor         5               
// intakePivot          motor         6               
// outakeTop            motor         7               
// outakeBottom         motor         8               
// pneuPiston1          digital_out   A               
// pneuPiston2          digital_out   B               
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
void driveTrain(){
// basically the way it works for explaining to others (AKA MICHAEL)--- motorYouWantToSpin.spin(direction, speed, velocity type)
// left back motor
driveLeftBack.spin(forward, (Controller1.Axis3.value() + Controller1.Axis1.value()), percent);
// right back motor
driveRightBack.spin(forward, (Controller1.Axis3.value() - Controller1.Axis1.value()), percent);
// left front motor
driveLeftFront.spin(forward, (Controller1.Axis3.value() + Controller1.Axis1.value()), percent);
// right front motor
driveRightFront.spin(forward, (Controller1.Axis3.value() - Controller1.Axis1.value()), percent);

}
void intakeControl(){
  if (Controller1.ButtonR1.pressing()){
      intakeRoller.spin(forward, 100, percent);
    }
  else if (Controller1.ButtonR2.pressing()){
      intakeRoller.spin(reverse, 100, percent);
    }
  else{
      intakeRoller.stop(brakeType::coast);
    }
  if (Controller1.ButtonB.pressing()){
    intakePivot.spin(forward, 100, percent);
  }
  else if (Controller1.ButtonY.pressing()){
    intakePivot.spin(reverse, 100, percent);
  }
  else{
    intakePivot.stop(brakeType::coast);
  }
}
void outakeControl(){
   if (Controller1.ButtonL1.pressing()){
      outakeTop.spin(forward, 100, percent);
      outakeBottom.spin(forward, 100, percent);
    }
    else if (Controller1.ButtonL2.pressing()){
      outakeTop.spin(reverse, 100, percent);
      outakeBottom.spin(reverse, 100, percent);
    }
    else{
      outakeTop.stop(brakeType::coast);
      outakeBottom.stop(brakeType::coast);
    }
}
void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
//tank drive code controls 
    driveTrain();
// intake code  controls 
    intakeControl();
// outake code controls
    outakeControl();
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}
void flapsControl(){
  if (Controller1.ButtonA.pressing()){
    pneuPiston1.set(true); 
    pneuPiston2.set(true);
  }
  else {
    pneuPiston1.set(false);
    pneuPiston2.set(false);
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
