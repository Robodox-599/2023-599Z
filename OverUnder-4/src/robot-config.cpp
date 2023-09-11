#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor driveLeftBack = motor(PORT9, ratio18_1, true);
motor driveRightBack = motor(PORT2, ratio18_1, false);
motor driveLeftFront = motor(PORT10, ratio18_1, true);
motor driveRightFront = motor(PORT1, ratio18_1, false);
controller Controller1 = controller(primary);
motor intakeMotor = motor(PORT6, ratio18_1, false);
motor cataMotor2 = motor(PORT7, ratio36_1, false);
digital_out pneuPiston1 = digital_out(Brain.ThreeWirePort.A);
digital_out pneuPiston2 = digital_out(Brain.ThreeWirePort.B);
limit cataSwitch = limit(Brain.ThreeWirePort.C);
motor cataMotor1 = motor(PORT5, ratio36_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}