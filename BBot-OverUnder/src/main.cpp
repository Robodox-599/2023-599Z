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
// descorer             motor         21              
// ---- END VEXCODE CONFIGURED DEVICES ----
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
// but it is basically how many degrees the robot turns when each motor does 1 full revolution in the appropriate direction 
// ill have to ask sam how to find this


void fwd(double distance, int speed){
  float Degree = (distance/WheelCircumference) * 360;
  driveLeftBack.spinFor(Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveRightBack.spinFor(Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveLeftFront.spinFor(Degree, rotationUnits::deg, speed, velocityUnits::pct, false);
  driveRightFront.spinF// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// driveLeftBack        motor         9               
// driveRightBack       motor         2               
// driveLeftFront       motor         10              
// driveRightFront      motor         1               
// Controller1          controller                    
// cataMotor2           motor         15              
// pneuPiston1          digital_out   A               
// pneuPiston2          digital_out   B               
// cataMotor1           motor         6               
// descorer             motor         21              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// driveLeftBack        motor         9               
// driveRightBack       motor         2               
// driveLeftFront       motor         10              
// driveRightFront      motor         1               
// Controller1          controller                    
// cataMotor2           motor         15              
// pneuPiston1          digital_out   A               
// pneuPiston2          digital_out   B               
// cataMotor1           motor         6               
// descorer             motor         21              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// driveLeftBack        motor         9               
// driveRightBack       motor         2               
// driveLeftFront       motor         10              
// driveRightFront      motor         1               
// Controller1          controller                    
// cataMotor2           motor         15              
// pneuPiston1          digital_out   A               
// pneuPiston2          digital_out   B               
// cataMotor1           motor         6               
// descorer             motor         21              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// driveLeftBack        motor         9               
// driveRightBack       motor         2               
// driveLeftFront       motor         10              
// driveRightFront      motor         1               
// Controller1          controller                    
// cataMotor2           motor         14              
// pneuPiston1          digital_out   A               
// pneuPiston2          digital_out   B               
// cataMotor1           motor         6               
// descorer             motor         21              
// ---- END VEXCODE CONFIGURED DEVICES ----
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
// descorer             motor         21              
// ---- END VEXCODE CONFIGURED DEVICES ----
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
// descorer             motor         21              
// ---- END VEXCODE CONFIGURED DEVICES ----
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
// but it is basically how many degrees the robot turns when each motor does 1 full revolution in the appropriate direction 
// ill have to ask sam how to find this


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
void cataRapid(int reps, float time){
  for(int i=0; reps <= i; i++){
    cataMotor1.spinFor(-180, rotationUnits::deg, 100, velocityUnits::pct, false);
    cataMotor1.spinFor(-180, rotationUnits::deg, 100, velocityUnits::pct);
    wait(time, msec);
  }
}
void descorerCmnd(bool val){
  if (val){
    descorer.spinFor(180, rotationUnits::deg, 100, velocityUnits::pct);
  } else {
    descorer.spinFor(-180, rotationUnits::deg, 100, velocityUnits::pct);
  }
}
void autonomous(void) {
 
}

// user control functions 
void arcadeDrive(float fwdIn, float trnIn){
//motorYouWantToSpin.spin(direction, speed, velocity type)
  driveLeftBack.spin(forward, (fwdIn + trnIn), percent);
  driveRightBack.spin(forward, (fwdIn - trnIn), percent);
  driveLeftFront.spin(forward, (fwdIn + trnIn), percent);
  driveRightFront.spin(forward, (fwdIn - trnIn), percent);
}

void rampUp(float maxSpeed){
  float currentSpeed = 0;
  for(int i; i <= maxSpeed, i++;){
    currentSpeed++;
    arcadeDrive(currentSpeed, 0);
  }
  arcadeDrive(maxSpeed, 0);
}

void driveControl(float fwdIn, float trnIn){
 float fwdVal;
 float trnVal; 
  if (fabs(fwdIn) >= 15 ){
    fwdVal = fwdIn;

  }
  else if(fabs(trnIn) >= 15 ){
    trnVal = trnIn;
  }
  else{ 
    fwdVal = 0;
     trnVal = 0;
  }
  arcadeDrive(fwdVal, trnVal);
}
void tankDrive(){
  driveLeftBack.spin(forward, Controller1.Axis3.value(), percent);
  driveLeftFront.spin(forward, Controller1.Axis3.value(), percent);
  driveRightBack.spin(forward, Controller1.Axis2.value(), percent);
  driveRightFront.spin(forward, Controller1.Axis2.value(), percent);
}
void cataControl(float time){
  if (Controller1.ButtonR1.pressing()){
     cataMotor1.spinFor(-180, rotationUnits::deg, 65, velocityUnits::pct, false);
     cataMotor2.spinFor(180, rotationUnits::deg, 65, velocityUnits::pct);
     wait(time, msec);
  } else {
     cataMotor1.stop(brakeType:: coast); 
     cataMotor2.stop(brakeType:: coast);
  }
}
void descorerControls(){
  if (Controller1.ButtonL1.pressing()){
    descorer.spin(forward, -100, velocityUnits::pct);
   } else if (Controller1.ButtonL2.pressing()) {
     descorer.spin(forward, 100, velocityUnits::pct);
   } else{
     descorer.stop(brakeType:: hold);
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
    //tankDrive();
    driveControl(Controller1.Axis3.value(), Controller1.Axis1.value());
    // outake code controls
    cataControl(250); // change this to how much time it takes to reset the cata at the slip position
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

or(Degree, rotationUnits::deg, speed, velocityUnits::pct);
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
void cataRapid(int reps, float time){
  for(int i=0; reps <= i; i++){
    cataMotor1.spinFor(-180, rotationUnits::deg, 100, velocityUnits::pct, false);
    cataMotor1.spinFor(-180, rotationUnits::deg, 100, velocityUnits::pct);
    wait(time, msec);
  }
}
void descorerCmnd(bool val){
  if (val){
    descorer.spinFor(180, rotationUnits::deg, 100, velocityUnits::pct);
  } else {
    descorer.spinFor(-180, rotationUnits::deg, 100, velocityUnits::pct);
  }
}
void autonomous(void) {
 
}

// user control functions 
void arcadeDrive(float fwdIn, float trnIn){
//motorYouWantToSpin.spin(direction, speed, velocity type)
  driveLeftBack.spin(forward, (fwdIn + trnIn), percent);
  driveRightBack.spin(forward, (fwdIn - trnIn), percent);
  driveLeftFront.spin(forward, (fwdIn + trnIn), percent);
  driveRightFront.spin(forward, (fwdIn - trnIn), percent);
}

void rampUp(float maxSpeed){
  float currentSpeed = 0;
  for(int i; i <= maxSpeed, i++;){
    currentSpeed++;
    arcadeDrive(currentSpeed, 0);
  }
  arcadeDrive(maxSpeed, 0);
}

void driveControl(float fwdIn, float trnIn){
 float fwdVal;
 float trnVal; 
  if (fabs(fwdIn) >= 15 ){
    fwdVal = fwdIn;

  }
  else if(fabs(trnIn) >= 15 ){
    trnVal = trnIn;
  }
  else{ 
    fwdVal = 0;
     trnVal = 0;
  }
  arcadeDrive(fwdVal, trnVal);
}
void tankDrive(){
  driveLeftBack.spin(forward, Controller1.Axis3.value(), percent);
  driveLeftFront.spin(forward, Controller1.Axis3.value(), percent);
  driveRightBack.spin(forward, Controller1.Axis2.value(), percent);
  driveRightFront.spin(forward, Controller1.Axis2.value(), percent);
}
void cataControl(float time){
  if (Controller1.ButtonR1.pressing()){
     cataMotor1.spinFor(-180, rotationUnits::deg, 65, velocityUnits::pct, false);
     cataMotor1.spinFor(-180, rotationUnits::deg, 65, velocityUnits::pct);
     wait(time, msec);
  } else {
     cataMotor1.stop(brakeType:: coast); 
     cataMotor2.stop(brakeType:: coast);
  }
}
void descorerControls(){
  if (Controller1.ButtonL1.pressing()){
    descorer.spin(forward, -100, velocityUnits::pct);
   } else if (Controller1.ButtonL2.pressing()) {
     descorer.spin(forward, 100, velocityUnits::pct);
   } else{
     descorer.stop(brakeType:: hold);
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
    //tankDrive();
    driveControl(Controller1.Axis3.value(), Controller1.Axis1.value());
    // outake code controls
    cataControl(250); // change this to how much time it takes to reset the cata at the slip position
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

