#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
motor frontLeft  = motor(PORT1, ratio18_1, true);
motor frontRight  = motor(PORT2, ratio18_1, false);
motor backLeft  = motor(PORT3, ratio18_1, true);
motor backRight = motor(PORT4, ratio18_1, false);


controller Controller1 = controller(primary);



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {author}                                                  */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

int main() {

while (true) {
    // Read joystick values
    int xAxis = Controller1.Axis1.position();
    int yAxis = Controller1.Axis2.position();
    int rotation = Controller1.Axis4.position();

    // Calculate motor speeds
    int frontLeftSpeed = yAxis + xAxis + rotation;
    int frontRightSpeed = yAxis - xAxis - rotation;
    int backLeftSpeed = yAxis - xAxis + rotation;
    int backRightSpeed = yAxis + xAxis - rotation;

    // Set motor speeds
    frontLeft.spin(forward, frontLeftSpeed, percent);
    frontRight.spin(forward, frontRightSpeed, percent);
    backLeft.spin(forward, backLeftSpeed, percent);
    backRight.spin(forward, backRightSpeed, percent);

    // Wait for the next iteration of the loop
    wait(20, msec);
}
}
