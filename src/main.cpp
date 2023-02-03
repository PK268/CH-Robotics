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
// shooter              motor_group   6, 7            
// rightDrive           motor_group   2, 10           
// leftDrive            motor_group   1, 9            
// indexer              digital_out   A               
// intake               motor_group   4, 5            
// stringSinglePiston   digital_out   B               
// stringDoublePiston   digital_out   C               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

float myVariable;

int shootStrength = 100;

// "when started" hat block

void rightForward() {
  rightDrive.setVelocity(Controller1.Axis2.position(), percent);
  rightDrive.spin(forward);
}

// "when Controller1 Axis3 changed" hat block
void leftForward() {
  leftDrive.setVelocity(Controller1.Axis3.position(), percent);
  leftDrive.spin(forward);
}

void pushDiscOut(){
    indexer.set(false);
}

void pushDiscIn(){
    indexer.set(true);
}

// "when Controller1 ButtonL2 pressed" hat block
void discInputMAX() {
  while (Controller1.ButtonL2.pressing()) {
    intake.setVelocity(100.0, percent);
    intake.spin(forward);
  wait(5, msec);
  }
  intake.stop();
}

// "when Controller1 ButtonL1 pressed" hat block
void NEWstringShooter() {
  if (Controller1.ButtonL1.pressing()) {
    Brain.Screen.print("Both Strings False");
    stringSinglePiston.set(false);
    stringDoublePiston.set(false);
    
    wait(3, sec);
    Brain.Screen.print("Both Strings True");
    stringSinglePiston.set(true);
    stringDoublePiston.set(true);
    
  }
}

// "when Controller1 ButtonR2 pressed" hat block
void intakeForward() {
  while (Controller1.ButtonR2.pressing()) {
    intake.setVelocity(75.0, percent);
    intake.spin(forward);
  wait(5, msec);
  }
  intake.stop();
}

// "when Controller1 ButtonY pressed" hat block
void intakeReverse() {
  while (Controller1.ButtonR1.pressing()) {
    intake.setVelocity(100.0, percent);
    intake.spin(reverse);
  wait(5, msec);
  }
  intake.stop();
}

// "when Controller1 ButtonA pressed" hat block
void shooterForward() {
  while (Controller1.ButtonA.pressing()) {
    shooter.setVelocity(100, percent);
    shooter.spin(forward);
  wait(5, msec);
  }
  shooter.stop();
}

void shooterMAX() {
  if(Controller1.ButtonUp.pressing()) {
    //shooter.setVelocity(87.5, percent);
    shooter.spin(forward, 12, voltageUnits::volt);
  }

  wait(1, sec);

  while(Controller1.ButtonUp.pressing()) {
    indexer.set(false);
    Brain.Screen.print("AutoFirePushout");
    Brain.Screen.newLine();
    wait(0.6, seconds);
    indexer.set(true);
    Brain.Screen.print("AutoFirePushIn");
    Brain.Screen.newLine();
    wait(0.125, seconds);
  }

indexer.set(true);
Brain.Screen.print("AutoFirePushIn");
shooter.stop();
  
}

void shooterMID() {
  if(Controller1.ButtonRight.pressing()) {
    //shooter.setVelocity(87.5, percent);
    shooter.spin(forward, 10, voltageUnits::volt);
  }

  wait(1, sec);

  while(Controller1.ButtonRight.pressing()) {
    indexer.set(false);
    Brain.Screen.print("AutoFirePushout");
    Brain.Screen.newLine();
    wait(0.6, seconds);
    indexer.set(true);
    Brain.Screen.print("AutoFirePushIn");
    Brain.Screen.newLine();
    wait(0.125, seconds);
  }

indexer.set(true);
Brain.Screen.print("AutoFirePushIn");
shooter.stop();
}

void shooterMIN() {
  if(Controller1.ButtonDown.pressing()) {
    //shooter.setVelocity(87.5, percent);
    shooter.spin(forward, 9, voltageUnits::volt);
  }

  wait(1, sec);

  while(Controller1.ButtonDown.pressing()) {
    indexer.set(false);
    Brain.Screen.print("AutoFirePushout");
    Brain.Screen.newLine();
    wait(0.6, seconds);
    indexer.set(true);
    Brain.Screen.print("AutoFirePushIn");
    Brain.Screen.newLine();
    wait(0.125, seconds);
  }

indexer.set(true);
Brain.Screen.print("AutoFirePushIn");
shooter.stop();
}

// "when Controller1 ButtonDown pressed" hat block
/*void shooterReverse() {
  while (Controller1.ButtonDown.pressing()) {
    shooter.setVelocity(100.0, percent);
    shooter.spin(reverse);
  wait(5, msec);
  }
  shooter.stop();
}*/

void stringShoot() {

  while(Controller1.ButtonB.pressing())

  stringDoublePiston.set(false);
  stringSinglePiston.set(false);
  Brain.Screen.print("stringShooter both false");
  wait(1, sec);
  stringDoublePiston.set(true);
  stringSinglePiston.set(true);
  Brain.Screen.print("stringShooter both true");

}

void stopMovement() {

  leftDrive.stop();
  rightDrive.stop();

}

void driveForwardSlowly() {

  leftDrive.setVelocity(10.0, percent);
  rightDrive.setVelocity(10.0, percent);
  leftDrive.spin(forward);
  rightDrive.spin(forward);

}

void driveBackSlowly() {

  leftDrive.setVelocity(10.0, percent);
  rightDrive.setVelocity(10.0, percent);
  leftDrive.spin(reverse);
  rightDrive.spin(reverse);

}


void rollerChange() {

  intake.setVelocity(50, percent);
  intake.spin(reverse);

}
/*
int[] nums = new int[5];

void kill(int may, int David) {
  while (David > 0) {
    if (may > David)
    David -= may;
  else
    may += 1;
  }
  
}*/



void autoFire() {

  if(Controller1.ButtonX.pressing()) {
    //shooter.setVelocity(87.5, percent);
    shooter.spin(forward, 11, voltageUnits::volt);
  }

  wait(1, sec);

  while(Controller1.ButtonX.pressing()) {
    indexer.set(false);
    Brain.Screen.print("AutoFirePushout");
    Brain.Screen.newLine();
    wait(0.6, seconds);
    indexer.set(true);
    Brain.Screen.print("AutoFirePushIn");
    Brain.Screen.newLine();
    wait(0.125, seconds);
  }

indexer.set(true);
Brain.Screen.print("AutoFirePushIn");
shooter.stop();

}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  
  /*
  rollerChange();
  driveForwardSlowly();
  wait(2.3, sec);
  intake.stop();
  stopMovement();
  driveBackSlowly();
  wait(1, sec);
  stopMovement();
  leftDrive.setVelocity(20.0, percent);
  rightDrive.setVelocity(20.0, percent);
  leftDrive.spin(forward);
  rightDrive.spin(reverse);
  wait(0.825, sec);
  stopMovement();
  */

  leftDrive.spin(forward, 50, pct);
  rightDrive.spin(forward, 50, pct);
  
wait(1, sec);
  leftDrive.setStopping(brake);
  rightDrive.setStopping(brake);
  
  leftDrive.stop();
  rightDrive.stop();
        
intake.setVelocity(100, percent);
      intake.spin(reverse);
    wait(0.2, sec);
    intake.stop();
    intake.setStopping(coast);
        //shooter.setVelocity(87.5, percent);
        shooter.spin(forward, 10, voltageUnits::volt);
        wait(2.5, seconds);
indexer.set(false);
      Brain.Screen.print("AutoFirePushout");
      Brain.Screen.newLine();
      wait(1.25, seconds);
      indexer.set(true);
      Brain.Screen.print("AutoFirePushIn");
      Brain.Screen.newLine();
      wait(0.2, seconds);
      indexer.set(false);
      Brain.Screen.print("AutoFirePushout");
      Brain.Screen.newLine();
      wait(1.25, seconds);
      indexer.set(true);
      Brain.Screen.print("AutoFirePushIn");
      Brain.Screen.newLine();
      wait(0.2, seconds);


shooter.setStopping(coast);
    shooter.stop();

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // register event handlers
  Controller1.Axis2.changed(rightForward);
  Controller1.ButtonL2.pressed(discInputMAX);
  Controller1.ButtonL1.pressed(stringShoot);
  Controller1.Axis3.changed(leftForward);
  Controller1.ButtonY.pressed(pushDiscIn);
  Controller1.ButtonX.pressed(autoFire);
  Controller1.ButtonA.pressed(shooterForward);
  Controller1.ButtonR2.pressed(intakeForward);
  Controller1.ButtonR1.pressed(intakeReverse); 
  //Controller1.ButtonA.pressed(shootString);
  Controller1.ButtonB.pressed(pushDiscOut);
  Controller1.ButtonUp.pressed(shooterMAX);
  Controller1.ButtonRight.pressed(shooterMID);
  Controller1.ButtonDown.pressed(shooterMIN);
  Controller1.ButtonLeft.pressed(autonomous);

  wait(15, msec);
  // post event registration

  // set default print color to black
  printf("\033[30m");

  // wait for rotation sensor to fully initialize
  wait(30, msec);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
