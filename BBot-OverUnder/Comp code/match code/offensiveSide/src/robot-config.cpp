#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LB = motor(PORT13, ratio18_1, true);
motor RB = motor(PORT12, ratio18_1, false);
motor LF = motor(PORT11, ratio18_1, true);
motor RF = motor(PORT2, ratio18_1, false);
motor cataLeft = motor(PORT14, ratio36_1, true);
motor cataRight = motor(PORT1, ratio36_1, false);
motor intakeMotor = motor(PORT10, ratio18_1, false);
digital_out wingsPiston = digital_out(Brain.ThreeWirePort.A);
inertial Inertial3 = inertial(PORT3);
digital_out blockerPiston = digital_out(Brain.ThreeWirePort.B);
limit LimitSwitchC = limit(Brain.ThreeWirePort.C);

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