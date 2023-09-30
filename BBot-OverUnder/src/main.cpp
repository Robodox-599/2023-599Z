// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// driveLeftBack        motor         2               
// driveRightBack       motor         1               
// driveLeftFront       motor         10              
// driveRightFront      motor         9               
// Controller1          controller                    
// cataLeft             motor         3               
// pneuPiston1          digital_out   A               
// cataRight            motor         4               
// descorer             motor         8               
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
float currentSpeed; // creating a speed varibale to store speed accross functions 
float revolutions2Angle; //defining later =b
// but it is basically how many degrees the robot turns when each motor does 1 full revolution in the appropriate direction 
// ill have to ask sam how to find this
float rampUp(float maxSpeed){
  float latestSpeed = 0;
  for(int i; i <= maxSpeed, i++;){
    latestSpeed++;
    return latestSpeed;
  }
   latestSpeed= maxSpeed;
  return latestSpeed;
}

void fwd(double distance, int MaxSpeed){
  float Degree = (distance/WheelCircumference) * 360;
  driveLeftBack.spinFor(Degree, rotationUnits::deg, rampUp(MaxSpeed), velocityUnits::pct, false);
  driveRightBack.spinFor(Degree, rotationUnits::deg, rampUp(MaxSpeed), velocityUnits::pct, false);
  driveLeftFront.spinFor(Degree, rotationUnits::deg, rampUp(MaxSpeed), velocityUnits::pct, false);
  driveRightFront.spinFor(Degree, rotationUnits::deg, rampUp(MaxSpeed), velocityUnits::pct);
}
void rev(double distance, int MaxSpeed){
  float Degree = (distance/WheelCircumference) * 360;
  driveLeftBack.spinFor(-Degree, rotationUnits::deg, rampUp(MaxSpeed), velocityUnits::pct, false);
  driveRightBack.spinFor(-Degree, rotationUnits::deg, rampUp(MaxSpeed), velocityUnits::pct, false);
  driveLeftFront.spinFor(-Degree, rotationUnits::deg, rampUp(MaxSpeed), velocityUnits::pct, false);
  driveRightFront.spinFor(-Degree, rotationUnits::deg, rampUp(MaxSpeed), velocityUnits::pct);
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
}
void cataRapid(int reps, float time){
  for(int i=0; reps <= i; i++){
    cataRight.spinFor(180, rotationUnits::deg, 100, velocityUnits::pct, false);
    cataLeft.spinFor(180, rotationUnits::deg, 100, velocityUnits::pct);
    wait(time, msec);
  }
}
void descorerCmnd(bool val){
  if (val){
    descorer.spinFor(180, rotationUnits::deg, 60, velocityUnits::pct);
  } else {
    descorer.spinFor(180, rotationUnits::deg, -60, velocityUnits::pct);
  }
}
void autonomous(void) {
 
}

// user control functions 
void cataControl(float time){
  if (Controller1.ButtonL1.pressing()){
    cataLeft.spinFor(180, rotationUnits::deg, 65, velocityUnits::pct, false);
    cataRight.spinFor(180, rotationUnits::deg, 65, velocityUnits::pct);
    wait(time, msec);
  } else if(Controller1.ButtonL2.pressing()){
    cataLeft.spin(forward, 20, velocityUnits::pct);
    cataRight.spin(forward, 20, velocityUnits::pct);
  } 
  else {
     cataLeft.stop(brakeType:: coast); 
     cataRight.stop(brakeType:: coast);
  }
}
void descorerControls(){
  if (Controller1.ButtonR1.pressing()){
    descorer.spin(forward, -80, velocityUnits::pct);
   } else if (Controller1.ButtonR2.pressing()) {
     descorer.spin(forward, 80, velocityUnits::pct);
   } else{
     descorer.stop(brakeType:: hold);
   }
}
void flapsControlOn(){
  pneuPiston1.set(true); 
}
void flapsControlOff(){
  pneuPiston1.set(false); 
}
void slowDrive(){
  if (Controller1.ButtonDown.pressing()){
    driveLeftBack.spin(forward, -20, percent);
    driveRightBack.spin(forward, 20, percent);
    driveLeftFront.spin(forward, -20, percent);
    driveRightFront.spin(forward, 20, percent);

  } else if (Controller1.ButtonRight.pressing()){
    driveLeftBack.spin(forward, 20, percent);
    driveRightBack.spin(forward, -20, percent);
    driveLeftFront.spin(forward, 20, percent);
    driveRightFront.spin(forward, -20, percent);
  } else{

  }
}
void arcadeDrive(float fwdIn, float trnIn){
//motorYouWantToSpin.spin(direction, speed, velocity type)
  driveLeftBack.spin(forward, (fwdIn + trnIn), percent);
  driveRightBack.spin(forward, (fwdIn - trnIn), percent);
  driveLeftFront.spin(forward, (fwdIn + trnIn), percent);
  driveRightFront.spin(forward, (fwdIn - trnIn), percent);
}
void driveControl(float fwdIn, float trnIn){
 float fwdVal;
 float trnVal; 
  if (fabs(fwdIn) >= 15 ){
    fwdVal = fwdIn-10;
  } else { 
    trnVal = 0;
  }
  if(fabs(trnIn) >= 15 ){
    trnVal = trnIn-15;
  } else { 
    trnVal = 0;
  }
  arcadeDrive(fwdVal, trnVal);
}
void usercontrol(void) {
  while (1) {
    //drive controls
    driveControl(Controller1.Axis3.value(), Controller1.Axis1.value());
    //slow arrow drive
    slowDrive();
    // outake controls
    cataControl(200); // change this to how much time it takes to reset the cata at the slip position
    // flaps controls
    Controller1.ButtonB.pressed(flapsControlOn);
    Controller1.ButtonY.pressed(flapsControlOff);
    //descorer controls
    descorerControls();
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
