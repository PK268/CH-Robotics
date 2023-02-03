using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor_group shooter;
extern motor_group rightDrive;
extern motor_group leftDrive;
extern digital_out indexer;
extern motor_group intake;
extern digital_out stringSinglePiston;
extern digital_out stringDoublePiston;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );