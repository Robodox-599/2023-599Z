// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LB                   motor         13              
// RB                   motor         12              
// LF                   motor         11              
// RF                   motor         2               
// cataLeft             motor         14              
// cataRight            motor         1               
// intakeMotor          motor         10              
// wingsPiston          digital_out   A               
// Inertial3            inertial      3               
// blockerPiston        digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/
//configuring chassis for auton
Drive chassis(

motor_group(LB, LF), /* left motor group */

motor_group(RB, RF), /* right motor group */

PORT3, /* inertial sensor port here */

4.125, /* wheel diameter*/

1.5, /*gear ratio after */

360/*Gyro scale, this is what the gyro/inertial reads when the robot is spun the robot 360 degrees.*/

);

int current_auton_selection = 0;
bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  while(auto_started == false){            //Changing the names below will only change their names on the
    Brain.Screen.clearScreen();            //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        Brain.Screen.printAt(50, 50, "DEFENSIVE AUTON");
        break;
      case 1:
        Brain.Screen.printAt(50, 50, "OFFENSIVE AUTON");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "AUTON SKILLS");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 3){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){  
    case 0:
      defensiveAuton();
     // kansasAuton(); //This is the default auton, if you don't select from the brain.
      break;        //Change these to be your own auton functions in order to use the auton selector.
    case 1:         //Tap the screen to cycle through autons.
      kansasAuton();
      break;
    case 2: 
      autonSkills();
      break;
 }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used  to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

float cataPos(bool pick, bool climb){
  // if pick is true then it will do the right motor position but if it is false then it will do the left motor position
  if (climb){
    if (pick){
      float rightPos = cataRight.position(degrees); // gets right motor encoder position and sets it to a variable
      float changeRight = (110-rightPos); // calculates the angle to turn to get to 180 from the motor encoder
      return changeRight; // returns the angle to be used in the cataControl function
    } else {
      float leftPos = cataLeft.position(degrees); // gets left motor encoder position and sets it to a variable
      float changeLeft = (110-leftPos); // calculates the angle to turn to get to 180 from the motor encoder
      return changeLeft; // returns the angle to be used in the cataControl function
    }
  } else {
    if (pick){
      float rightPos = cataRight.position(degrees); // gets right motor encoder position and sets it to a variable
      float changeRight = (180-rightPos); // calculates the angle to turn to get to 180 from the motor encoder
      return changeRight; // returns the angle to be used in the cataControl function
    } else {
      float leftPos = cataLeft.position(degrees); // gets left motor encoder position and sets it to a variable
      float changeLeft = (180-leftPos); // calculates the angle to turn to get to 180 from the motor encoder
      return changeLeft; // returns the angle to be used in the cataControl function
    }
  }
}
void cataControl(float times){
  // catapult control function
  // function takes in time to see how long it has to wait before running the commands again. 
  if (Controller1.ButtonL1.pressing()){
    // if l1 is being pressed it will spin the motors to a certain degree to get to the position 180
    // then it will reset the motor encoder values to 0 for both motors 
    // then it waits 
    cataLeft.spinFor((cataPos(true, false)), rotationUnits::deg, 65, velocityUnits::pct, false); // turns the perfect amount to get to 180
    cataRight.spinFor((cataPos(false, false)), rotationUnits::deg, 65, velocityUnits::pct); // turns the perfect amount to get to 180.
    cataLeft.setPosition(0, degrees); // resets encoder position to 0
    cataRight.setPosition(0, degrees); // resets encoder position to 0
   // waits set amount of time that was passed as a parameter before running it again
  } else if(Controller1.ButtonL2.pressing()){
    // if the l2 button is pressed it will give driver custom slow control commands on catapult 
    cataLeft.spin(forward, 20, velocityUnits::pct); // spins amount up to driver at a 20% speed
    cataRight.spin(forward, 20, velocityUnits::pct); // spins amount up to driver at a 20% speed
  } else if(Controller1.ButtonL2.pressing()){
    cataLeft.spinFor((cataPos(true, true)), rotationUnits::deg, 65, velocityUnits::pct, false); // turns the perfect amount to get to 180
    cataRight.spinFor((cataPos(false, true)), rotationUnits::deg, 65, velocityUnits::pct); // turns the perfect amount to get to 180.
    cataLeft.setPosition(0, degrees); // resets encoder position to 0
    cataRight.setPosition(0, degrees); // resets encoder position to 0
   
   // waits set amount of time that was passed as a parameter before running it again
  } else {
    // if there is no input then it will brake both motors 
     cataLeft.stop(brakeType:: coast); // brakes motor using coast 
     cataRight.stop(brakeType:: coast);// brakes motor using coast 
  }
}
void intakeControls(){
  if (Controller1.ButtonR1.pressing()){
    wait(85, msec);
    intakeMotor.spin(forward, -80, velocityUnits::pct);
   } else if (Controller1.ButtonR2.pressing()) {
     wait(85, msec);
     intakeMotor.spin(forward, 80, velocityUnits::pct);
   } else{
     intakeMotor.stop(brakeType:: hold);
   }
}
void flapsControlOn(){
  flapsPiston.set(true); 
}
void flapsControlOff(){
  flapsPiston.set(false); 
}
void slowDrive(){
  if (Controller1.ButtonLeft.pressing()){
    LB.spin(forward, -15, percent);
    RB.spin(forward, 15, percent);
    LF.spin(forward, -15, percent);
    RF.spin(forward, 15, percent);
  } else if (Controller1.ButtonRight.pressing()){
    LB.spin(forward, 15, percent);
    RB.spin(forward, -15, percent);
    LF.spin(forward, 15, percent);
    RF.spin(forward, -15, percent);
  } else{

  }
}
void arcadeDrive(float fwdIn, float trnIn){
//motorYouWantToSpin.spin(direction, speed, velocity type)
  LB.spin(forward, (fwdIn + trnIn), percent); // uses parameters as input to determine the speed in percent for the motor 
  RB.spin(forward, (fwdIn - trnIn), percent); // uses parameters as input to determine the speed in percent for the motor 
  LF.spin(forward, (fwdIn + trnIn), percent); // uses parameters as input to determine the speed in percent for the motor 
  RF.spin(forward, (fwdIn - trnIn), percent); // uses parameters as input to determine the speed in percent for the motor 
}
void driveControl(float fwdIn, float trnIn){
 float fwdVal; 
 float trnVal; 
  if (fabs(fwdIn) >= 10 ){
    fwdVal = fwdIn*.90;
  } else { 
    fwdVal = 0;
  }
  if(fabs(trnIn) >= 20 ){
    trnVal = trnIn*.80;
  } else { 
    trnVal = 0;
  }
  arcadeDrive(fwdVal, trnVal);
}
void tankDrive(float leftIn, float rightIn){
//motorYouWantToSpin.spin(direction, speed, velocity type)
  LB.spin(forward, (leftIn), percent); // uses parameters as input to determine the speed in percent for the motor 
  RB.spin(forward, (rightIn), percent); // uses parameters as input to determine the speed in percent for the motor 
  LF.spin(forward, (leftIn), percent); // uses parameters as input to determine the speed in percent for the motor 
  RF.spin(forward, (rightIn), percent); // uses parameters as input to determine the speed in percent for the motor 
}

bool pressing = false;
void toggle(){
  pressing = !pressing;
}
void tankDriveControl(float leftIn, float rightIn, bool pressing){
  float leftVal; 
  float rightVal; 
  if (pressing){
    leftVal = leftIn*.50;
    rightVal = rightIn*.50;
  }
  if (fabs(leftIn) >= 5 )
  {
    leftVal = leftIn*.95;
  } 
  else 
  { 
    leftVal = 0;
  }
  if(fabs(rightIn) >= 10 )
  {
    rightVal = rightIn*.90;
  }
  else 
  { 
    rightVal = 0;
  } 
  tankDrive(leftVal, rightVal);
}
// void slowToggleDrive(float leftIn, float rightIn){
//   float leftVal; 
//   float rightVal;
//   if (pressing == 1 ){ 
//     leftVal = leftIn*.50;
//     rightVal = rightIn*.50;
//     tankDrive(leftVal, rightVal);
//   }
//   else if (pressing != 1){
//     tankDriveControl(Controller1.Axis3.value(), Controller1.Axis2.value());
//   }
// }

int pressed = 0;
void press(){
  pressed += 1;
  if (pressed== 1){
    blockerPiston.set(true);
  } else if (pressed > 1){
    pressed = 0;
    blockerPiston.set(false);
  }
}
void usercontrol(void) {
  while (1) {
    //drive controls
    //driveControl(Controller1.Axis3.value(), Controller1.Axis1.value());
    tankDriveControl(Controller1.Axis3.value(), Controller1.Axis2.value(), pressing);
    //slowToggleDrive(Controller1.Axis3.value(), Controller1.Axis2.value());
    //toggle slow drive
    Controller1.ButtonDown.pressed(toggle);
    //slow arrow drive
    slowDrive();
    // outake controls
    cataControl(200); // change this to how much time it takes to reset the cata at the slip position
    // flaps controls
    Controller1.ButtonB.pressed(flapsControlOn);
    Controller1.ButtonY.pressed(flapsControlOff);
    // blocker controls
    Controller1.ButtonA.pressed(press);
    //descorer controls
    intakeControls();
   
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

