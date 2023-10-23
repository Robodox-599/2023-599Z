#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LB = motor(PORT2, ratio18_1, true);
motor RB = motor(PORT1, ratio18_1, false);
motor LF = motor(PORT10, ratio18_1, true);
motor RF = motor(PORT9, ratio18_1, false);
motor cataLeft = motor(PORT3, ratio36_1, true);
motor cataRight = motor(PORT4, ratio36_1, false);
motor intakeMotor = motor(PORT8, ratio18_1, false);
digital_out wingsPiston = digital_out(Brain.ThreeWirePort.A);
inertial Inertial7 = inertial(PORT7);
digital_out climbPiston = digital_out(Brain.ThreeWirePort.B);

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