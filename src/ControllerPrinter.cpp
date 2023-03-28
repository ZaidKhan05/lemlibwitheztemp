#include "ControllerPrinter.hpp"
#include "Flywheel.hpp"
#include "api.h"
#include "main.h"
#include "pros/misc.h"

double clip_num(double input, double max, double min) {
  if (input > max)
    return max;
  else if (input < min)
    return min;
  return input;
}

char* SpeedLine()
{
    char* toReturn = new char[13];
 
    int currentVelocity =clip_num(getFlywheelVelocity(), 102, 89);

    int i = 0;

    for (; i < (currentVelocity-89); i++)
    {
        toReturn[i] = '#';
    }

    for (; i < (110 - 89); i++) {
        toReturn[i] = ' ';
    }

    return toReturn;
}

void PrintInfo(void *)
{
  while (true)
  {
    if (getFlywheelTarget() > 80)
    {  master.print(0, 0, "RPM: %d / %d  ", ((int)getFlywheelVelocity()), ((int)getFlywheelTarget()));  }
    else
    {  master.print(0, 0, "RPM: %d / %d  ", ((int)getFlywheelVelocityCheap()), ((int)getFlywheelTarget()));}
    
    pros::delay(50);
    master.print(1, 0, "TMP: %d  ", getTemperature());
    pros::delay(250);
  }
}