using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LB;
extern motor RB;
extern motor LF;
extern motor RF;
extern motor cataLeft;
extern motor cataRight;
extern motor intakeMotor;
extern digital_out wingsPiston;
extern inertial Inertial3;
extern digital_out blockerPiston;
extern limit LimitSwitchC;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );