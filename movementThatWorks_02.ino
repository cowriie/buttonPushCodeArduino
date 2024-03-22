// -*- mode: C++ -*-

// Copyright (C) 2012 Mike McCauley
// $Id: Random.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(1,2,3); // mode 1, PUL pin 2, DIR pin 3

void setup()
{  
  stepper.setMaxSpeed(1000);
}

void loop()
{
    stepper.setSpeed(100);
    stepper.moveTo(630);
    stepper.runSpeed();
    // If at the end of travel go to the other end
    if (stepper.distanceToGo() == 0)
  {
      stepper.setSpeed(100);
      stepper.moveTo(0);
      stepper.runSpeed();
  }
}
