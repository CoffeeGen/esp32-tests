#ifndef GLOBALS_H
#define  GLOBALS_H

///////////////
// Includes
///////////////
#include <stdio.h>
#include <math.h>
#include <Preferences.h>
#include <usensor.h>
#include <led.h>
#include <mqsensor.h>
#include <transmitter.h>
#include <Servo.h>

/* create an instance of Preferences library */
Preferences preferences;
///////////////
// Variables
///////////////
USensor* uSensor;
MqSensor* mqSensor;

Led* greenLed;
Led* redLed;

Transmitter* rfTx;

Servo servo;

enum eLightState
{
    Off,
    On
};

eLightState lightState;

#endif  //GLOBALS_H
