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
// Controller1          controller                    
// driveLeftFront       motor         11              
// driveRightBack       motor         10              
// driveRightFront      motor         20              
// driveLeftBack        motor         1               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
using namespace vex;
competition Competition;

void pre_auton(void) {
  vexcodeInit();
}
void autonomous(void) {

}

void driveControl() {
  driveLeftBack.spin(forward, (1*(Controller1.Axis3.value() + Controller1.Axis1.value())* 1), percent);
  driveRightBack.spin(forward, (1*(Controller1.Axis3.value() - Controller1.Axis1.value())* 1), percent);
  driveLeftFront.spin(forward, (1*(Controller1.Axis3.value() + Controller1.Axis1.value())* 1), percent);
  driveRightFront.spin(forward, (1*(Controller1.Axis3.value() - Controller1.Axis1.value())* 1), percent);
}
void usercontrol(void) {
  while (1) {
    Brain.Screen.print("Meer is better than the rest of the rookies"); 
    driveControl();
    wait(20, msec);
  }
}
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
