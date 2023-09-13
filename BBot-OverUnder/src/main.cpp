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
// cataMotor2           motor         11              
// pneuPiston1          digital_out   A               
// pneuPiston2          digital_out   B               
// cataMotor1           motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cstring>
using namespace vex;
competition Competition;

//pre-auton function
// initializing and reseting
void pre_auton(void) {
  vexcodeInit();
}

//autonomous functions and main auton function

float WheelCircumference = (4.125 * 3.1415);
float revolutions2Angle; //defining later =b


void fwd(double distance, int speed){
  float Degree = (distance/WheelCircumference) * 360;
  driveLeftBack.spinFor(Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveRightBack.spinFor(Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveLeftFront.spinFor(Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveRightFront.spinFor(Degree, rotationUnits::deg, speed, velocityUnits::pct);
}
void rev(double distance, int speed){
  float Degree = (distance/WheelCircumference) * 360;
  driveLeftBack.spinFor(-Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveRightBack.spinFor(-Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveLeftFront.spinFor(-Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveRightFront.spinFor(-Degree, rotationUnits::deg, speed, velocityUnits::pct);
}

void tRight(double degrees, int speed){
  float Degree = (degrees * revolutions2Angle) * 360;
  driveLeftBack.spinFor(-Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveRightBack.spinFor(Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveLeftFront.spinFor(-Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveRightFront.spinFor(Degree, rotationUnits::deg, speed, velocityUnits::pct);
}
void tLeft(double degrees, int speed){
  float Degree = (degrees * revolutions2Angle) * 360;
  driveLeftBack.spinFor(Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveRightBack.spinFor(-Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveLeftFront.spinFor(Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveRightFront.spinFor(-Degree, rotationUnits::deg, speed, velocityUnits::pct);
}
void pistonCmnd(bool val){
  pneuPiston1.set(val);
  pneuPiston2.set(val);
}
void cataRapid(int reps, int speed){
  for(int i=0; reps <= i; i++){
    cataMotor1.spinFor(-reps, rotationUnits::rev, 100, velocityUnits::pct);
    cataMotor2.spinFor(-reps, rotationUnits::rev, 100, velocityUnits::pct);
  }
}
void autonomous(void) {
 
}

// user control functions 
void arcadeDrive(){
//motorYouWantToSpin.spin(direction, speed, velocity type)
driveLeftBack.spin(forward, (Controller1.Axis3.value() + Controller1.Axis1.value()), percent);
driveRightBack.spin(forward, (Controller1.Axis3.value() - Controller1.Axis1.value()), percent);
driveLeftFront.spin(forward, (Controller1.Axis3.value() + Controller1.Axis1.value()), percent);
driveRightFront.spin(forward, (Controller1.Axis3.value() - Controller1.Axis1.value()), percent);
}
void tankDrive(){
  driveLeftBack.spin(forward, Controller1.Axis3.value(), percent);
  driveLeftFront.spin(forward, Controller1.Axis3.value(), percent);
  driveRightBack.spin(forward, Controller1.Axis2.value(), percent);
  driveRightFront.spin(forward, Controller1.Axis2.value(), percent);
}
void cataControl(){
   if (Controller1.ButtonB.pressing()){
     cataMotor1.spin(reverse, 30, percent);
     cataMotor2.spin(reverse, 30, percent);
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
    wait(20, msec); 
  }
}
//main function
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}

