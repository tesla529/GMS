#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftIntake           motor         1               
// RightIntake          motor         3               
// Tray                 motor         5               
// RightDrive           motor         7               
// LeftDrive            motor         6               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

competition Competition;

void setDrive(int l,int r);
void setIntake(int p);

void pre_auton(void) {
  vexcodeInit();

}

void autonomous(void) {
 setDrive(-100,-100);
 wait(500,msec);
 setDrive(1000,100); 
 wait(1000,msec);
 setDrive(0,0);
}

void usercontrol(void) {

  while (1) {

    setDrive(Controller1.Axis3.value()+Controller1.Axis4.value(),Controller1.Axis3.value()-Controller1.Axis4.value());

    

    if(Controller1.ButtonL2.pressing()) {
      setIntake(100);
    }
    else if(Controller1.ButtonL1.pressing()) {
      setIntake(-100);
    }
    else {
      setIntake(0);
    }

    if(Controller1.ButtonUp.pressing()) {
      Tray.spin(fwd,100,pct);
    }
    else if(Controller1.ButtonDown.pressing()) {
      Tray.spin(fwd,-100,pct);
    }
    else {
      Tray.spin(fwd,0,pct);
    }

    

    wait(20, msec);
  }
}
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}

void setDrive(int l,int r) {
  LeftDrive.spin(fwd,l,pct);
  RightDrive.spin(fwd,r,pct);
}

void setIntake(int p) {
  LeftIntake.spin(fwd,p,pct);
  RightIntake.spin(fwd,p,pct);
}