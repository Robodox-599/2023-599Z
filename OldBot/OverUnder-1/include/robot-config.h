using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor driveLeftBack;
extern motor driveRightBack;
extern motor driveLeftFront;
extern motor driveRightFront;
extern controller Controller1;
extern motor intakeRoller;
extern motor intakePivot;
extern motor outakeTop;
extern motor outakeBottom;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );