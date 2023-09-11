#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor driveLeftBack = motor(PORT9, ratio18_1, false);
motor driveRightBack = motor(PORT20, ratio18_1, true);
motor driveLeftFront = motor(PORT10, ratio18_1, false);
motor driveRightFront = motor(PORT19, ratio18_1, true);
controller Controller1 = controller(primary);
motor outakeMotor = motor(PORT5, ratio18_1, false);
motor intakeRoller = motor(PORT6, ratio18_1, false);
digital_out pneuPiston1 = digital_out(Brain.ThreeWirePort.A);
digital_out pneuPiston2 = digital_out(Brain.ThreeWirePort.B);

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