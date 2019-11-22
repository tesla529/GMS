#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftIntake = motor(PORT1, ratio36_1, false);
motor RightIntake = motor(PORT3, ratio36_1, true);
motor Tray = motor(PORT5, ratio18_1, false);
motor RightDrive = motor(PORT7, ratio18_1, true);
motor LeftDrive = motor(PORT6, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}