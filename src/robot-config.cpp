#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor shooterMotorA = motor(PORT6, ratio6_1, true);
motor shooterMotorB = motor(PORT7, ratio6_1, false);
motor_group shooter = motor_group(shooterMotorA, shooterMotorB);
motor rightDriveMotorA = motor(PORT2, ratio6_1, false);
motor rightDriveMotorB = motor(PORT10, ratio6_1, false);
motor_group rightDrive = motor_group(rightDriveMotorA, rightDriveMotorB);
motor leftDriveMotorA = motor(PORT1, ratio6_1, true);
motor leftDriveMotorB = motor(PORT9, ratio6_1, true);
motor_group leftDrive = motor_group(leftDriveMotorA, leftDriveMotorB);
digital_out indexer = digital_out(Brain.ThreeWirePort.A);
motor intakeMotorA = motor(PORT4, ratio36_1, false);
motor intakeMotorB = motor(PORT5, ratio36_1, true);
motor_group intake = motor_group(intakeMotorA, intakeMotorB);
digital_out stringSinglePiston = digital_out(Brain.ThreeWirePort.B);
digital_out stringDoublePiston = digital_out(Brain.ThreeWirePort.C);

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