#include "vex.h"


// constants and other useful functions for auton
void default_constants(){
  chassis.set_constants(  
          /* max voltage | kp constants | ki constants | kd constants |  start ki constants */
/* turn  */    12        ,      .3      ,     .03      ,      6       ,         15          ,
/* drive */    12        ,      1.5     ,       0      ,      10      ,         0           ,
/* swing */    12        ,      .3      ,     .001     ,      2       ,         15          , 
/*heading*/    12        ,      .4      ,       0      ,      1       ,         0           ); 
  chassis.set_exit_conditions(
         /* settle error   |     settle time    |   timeout   */
/*swing*/  1               ,        300         ,     2000    ,
/*turn*/   1               ,        250         ,     1500    ,
/*drive*/  1.5             ,        250         ,     4000    );
}
float cataPosition(bool pick){
  // if pick is true then it will do the right motor position but if it is false then it will do the left motor position
  if (pick){
    float rightPos = cataRight.position(degrees); // gets right motor encoder position and sets it to a variable
    float changeRight = (180-rightPos); // calculates the angle to turn to get to 180 from the motor encoder
    return changeRight; // returns the angle to be used in the cataControl function
  } else{
    float leftPos = cataLeft.position(degrees); // gets left motor encoder position and sets it to a variable
    float changeLeft = (180-leftPos); // calculates the angle to turn to get to 180 from the motor encoder
    return changeLeft; // returns the angle to be used in the cataControl function
  }
}
void cataControls(float times){
  // catapult control function
  // function takes in time to see how long it has to wait before running the commands again. 
  cataLeft.spinFor((cataPosition(true)), rotationUnits::deg, 65, velocityUnits::pct, false); // turns the perfect amount to get to 180
  cataRight.spinFor((cataPosition(false)), rotationUnits::deg, 65, velocityUnits::pct); // turns the perfect amount to get to 180.
  cataLeft.setPosition(0, degrees); // resets encoder position to 0
  cataRight.setPosition(0, degrees); // resets encoder position to 0
//  this_thread::sleep_for(times);// waits set amount of time that was passed as a parameter before running it again
}
// real autons down here
void kansasAuton(){
  intakeMotor.setPosition(0, degrees);
  intakeMotor.setBrake(brakeType::hold);
  flapsPiston.set(true); 
  wait(100, msec);
  flapsPiston.set(false);
  chassis.drive_distance(59);
  intakeMotor.spinFor(-110, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.turn_to_angle(120, 8);
  intakeMotor.spinFor(110, rotationUnits::deg, 100, velocityUnits::pct, true);
  flapsPiston.set(true); 
  chassis.drive_distance(32);
  flapsPiston.set(false); 
  chassis.drive_distance(-12);
  chassis.turn_to_angle(270);
  chassis.drive_distance(25);
  intakeMotor.spinFor(-110, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.drive_distance(-12);
  chassis.turn_to_angle(180);
  chassis.drive_distance(40);
  //chassis.turn_to_angle(180);
  // chassis.drive_distance(51);
  chassis.turn_to_angle(395);
  intakeMotor.spinFor(110, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.drive_distance(35);
}

void defensiveAuton(){
  intakeMotor.setPosition(0, degrees);
  intakeMotor.setBrake(brakeType::hold);
  flapsPiston.set(true); 
  wait(500, msec);
  flapsPiston.set(false);
  intakeMotor.spinFor(-110, rotationUnits::deg, 100, velocityUnits::pct, true);
  wait(1000, msec);
  chassis.drive_distance(-8);
  chassis.turn_to_angle(270);
  intakeMotor.spinFor(110, rotationUnits::deg, 100, velocityUnits::pct, true);
  chassis.drive_distance(-30);
  chassis.drive_distance(35);
  chassis.turn_to_angle(230);
  chassis.drive_distance(36);
  // intakeMotor.spinFor(-110, rotationUnits::deg, 100, velocityUnits::pct, true);
  // chassis.drive_distance(-10);
  // chassis.turn_to_angle(-90);
  // wingsPiston.set(true); 
  // chassis.drive_distance(-39);
  // chassis.drive_distance(50);
  // wingsPiston.set(false);
  // chassis.turn_to_angle(220);
  // intakeMotor.spinFor(110, rotationUnits::deg, 100, velocityUnits::pct, true);
  // chassis.drive_distance(35);
}

void autonSkills(){
  chassis.drive_distance(35);
  chassis.drive_distance(-8);
  chassis.turn_to_angle(94);
  chassis.drive_distance(-12);
  // for(int i=0; i<=46; i++){
  // cataControls(100);
  // f
  chassis.drive_distance(25);
  chassis.turn_to_angle(125);
  chassis.drive_distance(15);
  chassis.turn_to_angle(90);
  chassis.drive_distance(45);
  flapsPiston.set(true);
  chassis.drive_distance(35);
  chassis.drive_distance(-15);
  flapsPiston.set(false);
  chassis.turn_to_angle(90);
  flapsPiston.set(true);
  chassis.drive_distance(35);
  chassis.left_swing_to_angle(360);

 }
//useless stuff down heree 
