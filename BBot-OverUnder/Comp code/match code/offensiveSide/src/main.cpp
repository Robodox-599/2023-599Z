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
// flapsPiston          digital_out   A               
// Inertial3            inertial      3               
// wedgePiston          digital_out   B               
// LimitSwitchC         limit         C               
// ---- END VEXCODE CONFIGURED DEVICES ----
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
    autonSkills();
     // defensiveAuton(); //This is the default auton, if one is not selected from the brain
      break;            //Tap the screen to cycle through autons.
    case 1:        
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
/*----------------------------------------------------------------*/
/*                           Variable Declaration Below                                                      */

/*Defining all global variables nessasary throughout the functions declared below*/

float modifier = 1.0;  /*Modifier variable used to modify speed in the slow drivetoggle function (declared later in the program)*/

bool toggleState = false; /*Toggle state variable used to track the state of the toggle slow drive toggle function (declared later in the program)*/

bool latch = true; /*Latch variable used to track the state of the Latch in the slow drive toggle function (declared later in the program)*/

bool wedgedToggled = false; /*Wedge toggle variable used to track the state of the toggle wedge toggle function (declared later in the program)*/

bool flapsToggled = false; /*Flaps toggle variable used to track the state of the toggle Flaps toggle function (declared later in the program)*/

/*                               End Variable Declaration                                                       */
/*----------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/
/*                           Function Declaration Below                                                                                           */

float cataPos(bool pick, float cataResetAngle){
 /*This is the Cata Failsafe Function it tracks the Catapult motors position
 using the built in motor encoders in the catapult motors with the encoder
 position it calculates the perfect amount of degrees nessasary to turn the
 catapult in order to reset it back to the cataResetAngle which is passed
 in as a parameter. This function takes 2 parameters, the pick parameter as a
 boolean which determines if the right motor position is being tracked and corrected
 or if the left motor position is being tracked and corrected. It also takes in another
 parameter called cataResetAngle which is the set amount of degrees the motor will turn
 in order to reset the catapult back to its unluanched state */
 if (pick){
   float rightPos = cataRight.position(degrees); // gets right motor encoder position and sets it to a variable
   float changeRight = (cataResetAngle-rightPos); // calculates the angle to turn to get to cataResetAngle from the motor encoder
   return changeRight; // returns the angle to be used in the cataControl function
 } else {
   float leftPos = cataLeft.position(degrees); // gets left motor encoder position and sets it to a variable
   float changeLeft = (cataResetAngle-leftPos); // calculates the angle to turn to get to cataResetAngle from the motor encoder
   return changeLeft; // returns the angle to be used in the cataControl function
 }
}

void cataControl(float cataResetAngle){
 /*This is the Catapult Control Function takes in cata reset angle as a parameter to pass
 into the Catapult Failsafe/ cataPos function in order to correct the custom adjustments
 the driver used as they used the custom 20% speed adjustment */

 if (Controller1.ButtonL1.pressing()){
   /* if l1 is being pressed it will spin the motors to a certain degree to get to the position 180
   then it will reset the motor encoder values to 0 for both motors */

/* turns the perfect amount to get to cataResetAngle. */
   cataLeft.spinFor((cataPos(true, cataResetAngle)), rotationUnits::deg, 65, velocityUnits::pct, false); 
   cataRight.spinFor((cataPos(false, cataResetAngle)), rotationUnits::deg, 65, velocityUnits::pct);
/* resets encoder position to 0 */
   cataLeft.setPosition(0, degrees); 
   cataRight.setPosition(0, degrees); 
 } else if(Controller1.ButtonL2.pressing()){
   // if the l2 button is pressed it will give driver custom slow control commands on catapult

/*  spins amount up to driver at a 20% speed */
   cataLeft.spin(forward, 20, velocityUnits::pct); 
   cataRight.spin(forward, 20, velocityUnits::pct); 
 } else {
   // if there is no input then it will brake both motors

	/*brakes motor using coast*/
    cataLeft.stop(brakeType:: coast); 
    cataRight.stop(brakeType:: coast);

 }
}
void intakeControls(){
 //intake control function
 if (Controller1.ButtonR1.pressing()){
  /* if r1 is being pressed then it will wait 0.085 of a second before spinning the arm up
   it waits .085 of a second in order to remove the current from the hold braking, this way
   there are no issues with the arm jumping down before going up, or jumping up before going down */
  /*Waits 85 Miliseconds*/
  wait(85, msec); 
  /* spins the intake Motor at 80 percent speed and spins it forward to spin the arm up*/
  intakeMotor.spin(forward, -80, velocityUnits::pct); 
} else if (Controller1.ButtonR2.pressing()) {
  /* if r2 is being pressed then it will wait 0.085 of a second before spinning the arm up
  it waits .085 of a second in order to remove the current from the hold braking, this way
  there are no issues with the arm jumping down before going up, or jumping up before going down */
  /*Waits 85 Miliseconds*/
  wait(85, msec); 
  /* spins the intake Motor at 80 percent speed and spins it forwardto spin the arm down*/
  intakeMotor.spin(forward, 80, velocityUnits::pct); 
 } else{
  // if there is no input then it will brake and hold the arm.
  /*sets brake type to Hold so then the Intake arm will remain at the position it is at.*/
    intakeMotor.stop(brakeType:: hold);  }
}
void slowTurn(){
 /*This is the slow turn function, it gives driver the ability to use the arrow buttons on the controller  to turn at 15% speed for more accurate turns.*/
 if (Controller1.ButtonLeft.pressing()){
   // if the left arrow is being pressed, then it will turn left at 15% speed
   LB.spin(forward, -15, percent);
   RB.spin(forward, 15, percent);
   LF.spin(forward, -15, percent);
   RF.spin(forward, 15, percent);
 } else if (Controller1.ButtonUp.pressing()){
   // if the right arrow is being pressed, then it will turn right at 15% speed
   LB.spin(forward, 15, percent);
   RB.spin(forward, -15, percent);
   LF.spin(forward, 15, percent);
   RF.spin(forward, -15, percent);
 } else{
   // if there is no input no robot changes will occur.
 }
}

void toggle(bool input, float mod){
 /*This is the toggle function, it uses pressing input as a parameter, to control the ToggleState variable, in order to control the modifier value.
  This function applies a gate and latch method of toggle in order to propperly toggle through slow driving and regular.*/
 if(input && latch){
   // if both the input and the latch are true, then it will inverse the values of both toggleState and latch.
   toggleState = !toggleState;
   latch = !latch;
 }
 else if(!input){
   // if there is no input then inverse the latch variable
  latch = !latch;
 }
 if(toggleState){
   //if the toggle state variable is true then it will change the value of the modifier to a value passed in as a parameter through the main function.
  modifier = mod;
 }
 else{
   // if the toggle state is false then it will return the modifier to its original state of 1.
  modifier = 1;
 }
}
void arcadeDrive(float fwdIn, float trnIn){
/*This is the arcade drive function. This uses the inputs passed in as parameters to calculate if there is turning or if there is regular driving. Overall this function was created in order to create modular code throughout the program.*/
 LB.spin(forward, (fwdIn + trnIn), percent); // uses parameters as input to determine the speed in percent for the motor
 RB.spin(forward, (fwdIn - trnIn), percent); // uses parameters as input to determine the speed in percent for the motor
 LF.spin(forward, (fwdIn + trnIn), percent); // uses parameters as input to determine the speed in percent for the motor
 RF.spin(forward, (fwdIn - trnIn), percent); // uses parameters as input to determine the speed in percent for the motor
}
void tankDrive(float leftIn, float rightIn){
/* This is the tank drive function. This uses the inputs passed in as parameters to drive the left or right motors. Overall this function was created in order to create modular code throughout the program.*/
 LB.spin(forward, (leftIn), percent); // uses parameters as input to determine the speed in percent for the motor
 RB.spin(forward, (rightIn), percent); // uses parameters as input to determine the speed in percent for the motor
 LF.spin(forward, (leftIn), percent); // uses parameters as input to determine the speed in percent for the motor
 RF.spin(forward, (rightIn), percent); // uses parameters as input to determine the speed in percent for the motor
}

void arcadeDriveControl(float fwdIn, float trnIn){
 /*This is the arcade Drive control function. This function takes in two inputs as the joystick turn and forward values. It will then put a deadzone on the joysticks and pass the new values into the Arcade Drive function where the robot will start to drive. */
 float fwdVal;
 float trnVal;
 if (fabs(fwdIn) >= 10 ){
   /* If the absolute value of the input is greater than 10% then the variable FwdVal will be changed to be 90% of the input from the user, this is used to set the deadzones. Also, this will apply the modifier in order to change the output to make sure that the slow toggle will limit the max speed to be the modifier value, which was defined in the toggle function*/
   fwdVal = fwdIn*.90;
 } else {
   /*If the absolute value of the input is less than 10% then the variable FwdVal will be changed to be 0, and ignore the input from the user. This is a part of the deadzones. */
   fwdVal = 0;
 }
 if(fabs(trnIn) >= 20 ){
    /* If the absolute value of the input is greater than 20% then the variable TrnVal will be changed to be 80% of the input from the user, this is used to set the deadzones. Also, this will apply the modifier in order to change the output to make sure that the slow toggle will limit the max speed to be the modifier value, which was defined in the toggle function*/
   trnVal = trnIn*.80;
 } else {
   /*If the absolute value of the input is less than 20% then the variable TrnVal will be changed to be 0, and ignore the input from the user. This is a part of the deadzones. */
   trnVal = 0;
 }
 /*After deadzones are calculated, these new Values will be passed into the Arcade Drive function in order to drive the robot*/
 arcadeDrive(fwdVal, trnVal);
}
void tankDriveControl(float leftIn, float rightIn){
 float leftVal;
 float rightVal;
 if (fabs(leftIn) >= 5 ){\
    /* If the absolute value of the input is greater than 5% then the variable leftVal will be changed to be 95% of the input from the user, this is used to set the deadzones. Also, this will apply the modifier in order to change the output to make sure that the slow toggle will limit the max speed to be the modifier value, which was defined in the toggle function*/
   leftVal = leftIn*.95*modifier;
 } else {
   /*If the absolute value of the input is less than 5% then the variable leftVal will be changed to be 0, and ignore the input from the user. This is a part of the deadzones. */
   leftVal = 0;
 }
 if(fabs(rightIn) >= 10 ){
   /* If the absolute value of the input is greater than 10% then the variable rightVal will be changed to be 95% of the input from the user, this is used to set the deadzones. Also, this will apply the modifier in order to change the output to make sure that the slow toggle will limit the max speed to be the modifier value, which was defined in the toggle function*/
   rightVal = rightIn*modifier*.90;
 } else {
    /*If the absolute value of the input is less than 10% then the variable rightVal will be changed to be 0, and ignore the input from the user. This is a part of the deadzones. */
   rightVal = 0;
 }
 /*After deadzones are calculated, these new Values will be passed into the tankDrive function in order to drive the robot*/
 tankDrive(leftVal, rightVal);
}
void toggleWedge(){
/*This is the toggleWedge function, it takes in no parameters but uses the value of the wedgedToggled in
order to determine if the wedgePiston should be set to true or false. It is called in the main function
as a callback for the .pressed() function. It will first switch the wedgeToggled value to inverse it, then
check the state of the WedgeToggled*/
 wedgedToggled = !wedgedToggled; // inverses state of wedgeToggled
 if (wedgedToggled){
   //if wedgedToggled is true then it will switch the wedge piston to be the true
   wedgePiston.set(true);
 } else{
   //if wedgedToggled is false then it will switch the wedgePiston to be false
   wedgePiston.set(false);
 }
}

void toggleFlaps(){
/*This is the toggleFlaps function, it takes in no parameters but uses the value of the flapsToggled in
order to determine if the flapsPiston should be set to true or false. It is called in the main function
as a callback for the .pressed() function. It will first switch the flapsToggled value to inverse it, then
check the state of the flapsToggled*/
 flapsToggled = !flapsToggled; // inverses state of flapsToggled
 if (flapsToggled){
   //if flapsToggled is true then it will switch the wedge piston to be the true
   flapsPiston.set(true);
 } else{
   //if flapsToggled is false then it will switch the wedge piston to be the false
   flapsPiston.set(false);
 }
}
void skillsSetup() {
  chassis.drive_distance(35);
  chassis.drive_distance(-8);
  chassis.turn_to_angle(94);
  chassis.drive_distance(-12);
}

/*                         End Function   Declarations                                                                                                                        */
/*-----------------------------------------------------------------------------------------------*/


void usercontrol(void) {
  while (1) {
    //drive controls
    //arcadeDriveControl(Controller1.Axis3.value(), Controller1.Axis1.value());
    tankDriveControl(Controller1.Axis3.value(), Controller1.Axis2.value());
    //toggle slow drive
    //slow arrow drive
    slowTurn();
    // outake  and climb controls
    /*float climbAngle, float cataResetAngle*/
    cataControl(180);
    // flaps controls
    // Controller1.ButtonUp.pressed();
    toggle(Controller1.ButtonRight.pressing(), 0.4);
    Controller1.ButtonX.pressed(skillsSetup);
    Controller1.ButtonB.pressed(toggleFlaps); // calls the toggle function for the flaps when the button is pressed
    // wedge controls
    Controller1.ButtonY.pressed(toggleWedge); // calls the toggle function for wedge when the button is pressed
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

