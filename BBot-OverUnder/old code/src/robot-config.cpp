#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor driveLeftBack = motor(PORT2, ratio18_1, true);
motor driveRightBack = motor(PORT1, ratio18_1, false);
motor driveLeftFront = motor(PORT10, ratio18_1, true);
motor driveRightFront = motor(PORT9, ratio18_1, false);
controller Controller1 = controller(primary);
motor cataLeft = motor(PORT3, ratio36_1, true);
digital_out pneuPiston1 = digital_out(Brain.ThreeWirePort.A);
motor cataRight = motor(PORT4, ratio36_1, false);
motor descorer = motor(PORT8, ratio18_1, false);

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