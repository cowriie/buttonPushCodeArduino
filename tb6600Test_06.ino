/*
  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/InputPullupSerial
*/

//Include the Arduino Stepper Library
#include <Stepper.h>
 
// Define Constants
 
// Number of steps per internal motor revolution
const float STEPS_PER_REV = 1600; 
 
//  Amount of Gear Reduction
const float GEAR_RED = 2;
 
// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
 
// Define Variables
 
// Number of Steps Required
int StepsRequired;
 
// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 2,3
// Connected to ULN2003 Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-3-2-4 for proper step sequencing
 
Stepper steppermotor(STEPS_PER_REV, 3,2);

void setup() {

  //configure pin 7 as an input and enable the internal pull-up resistor
  pinMode(7, INPUT_PULLUP);

}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(7);


  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == LOW) {

       // Rotate CCW 1/2 turn slowly
       
       StepsRequired  = - 0.77*STEPS_PER_OUT_REV; 
       steppermotor.setSpeed(25);   
       steppermotor.step(StepsRequired);
       delay(1000);
  
       // Rotate CCW 1/2 turn quickly
       StepsRequired  = 0.77*STEPS_PER_OUT_REV;   
       steppermotor.setSpeed(100);  
       steppermotor.step(StepsRequired);
       delay(2000);

  }
    
  }
