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
// Vision2              vision        2               
// leftBackMotor        motor         3               
// leftFrontMotor       motor         4               
// rightBackMotor       motor         5               
// rightFrontMotor      motor         6               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
using namespace vex;
competition Competition;
int   screen_origin_x = 150;
int   screen_origin_y = 20;
int   screen_width    = 316;
int   screen_height   = 212;


void
drawObject( vision::object &obj, vex::color c ) {
    int labelOffset = 0;
    
    Brain.Screen.setPenColor( vex::color::yellow );
    Brain.Screen.drawRectangle( screen_origin_x + obj.originX, screen_origin_y + obj.originY, obj.width, obj.height, c );
    Brain.Screen.setFont( vex::fontType::mono12 );
    
    if( obj.originX > 280 )
      labelOffset = -40;
    if( obj.originY > 10 )
      Brain.Screen.printAt( screen_origin_x + obj.originX + labelOffset, screen_origin_y + obj.originY-3, "Sig %o", obj.id );
    else
      Brain.Screen.printAt( screen_origin_x + obj.originX + labelOffset, screen_origin_y + obj.originY+10, "Sig %o", obj.id );
}

// function to draw all objects found
void
drawObjects( vision &v, vex::color c, bool clearScreen ) {
    if( clearScreen ) {
      Brain.Screen.setPenColor( vex::color::black );
      Brain.Screen.drawRectangle( screen_origin_x, screen_origin_y, screen_width, screen_height, vex::color::black );
    }
    
    for(int i=0;i<v.objectCount;i++)
      drawObject( v.objects[i], c );
}

bool turning = false;

void
driveTurn( int speed ) {
  int   drive_l_front = speed;
  int   drive_l_back  = speed;
  int   drive_r_front = -speed;
  int   drive_r_back  = -speed;

  if( speed != 0 ){
    turning = true;
  }
  else{
    turning = false;
  }
  leftFrontMotor.spin( vex::directionType::fwd, drive_l_front, vex::velocityUnits::rpm );
  leftBackMotor.spin( vex::directionType::fwd, drive_l_back , vex::velocityUnits::rpm );
  rightFrontMotor.spin( vex::directionType::fwd, drive_r_front, vex::velocityUnits::rpm );
  rightBackMotor.spin( vex::directionType::fwd, drive_r_back , vex::velocityUnits::rpm );
}
#define TARGET  150

void eventButtonY() {
  while(1) {
    // get latest objects
    int numberObjects = Vision2.takeSnapshot(Vision2__SIG_1);

    if( numberObjects > 0 ) {
      // make a copy
      vex::vision::object obj = Vision2.objects[0];

      if( obj.centerY != 0 && obj.width > 20 && obj.height > 20 ) {
        int error = obj.centerY - TARGET;

        // simple P control
        int drive = error;
        if( drive > 50 ) drive = 50;
        if( drive < -50 ) drive = -50;

        // object is found and centered
        if( obj.centerY > (TARGET-15) && obj.centerY < (TARGET+15) ) {
          driveTurn(0);
        }
        else {
          driveTurn( drive );
        }
      } 
    }
    else {
      // look for object
      driveTurn( 50 );
    }
    if( Controller1.ButtonX.pressing() ) {
      driveTurn(0);
      return;
    }
    vex::this_thread::sleep_for(50);
  }
}
void pre_auton(void) {
  vexcodeInit();
}
void autonomous(void) {
}
void usercontrol(void) {
  while (1) {
    wait(20, msec);
  }
}
int main() {
  // Draw an area representing the vision sensor field of view
  Brain.Screen.clearScreen( vex::color::black );
  Brain.Screen.setPenColor( vex::color::green );
  Brain.Screen.drawRectangle( screen_origin_x-1, screen_origin_y-1, screen_width+2, screen_height+2 );
  Controller1.ButtonY.pressed( eventButtonY );
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // Run the pre-autonomous function.
  pre_auton();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    // request any objects with signature 1
    int numberObjects = Vision2.takeSnapshot(Vision2__SIG_1);
    Brain.Screen.setPenColor( vex::color::white );
    Brain.Screen.setFont( mono20 );
    Brain.Screen.setCursor( 2, 2 );
    Brain.Screen.print( "Sig 1 %2d", (int)numberObjects );
    Brain.Screen.setCursor( 3, 2 );
    Brain.Screen.print( "C %4d", Vision2.objects[0].centerY  );
    // draw any objects found
    drawObjects( Vision2, vex::color::blue, true );
    // run 10 times/second
    this_thread::sleep_for(100);      
  }
}
