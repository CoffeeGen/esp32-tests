#include "init.h"
#include <Arduino.h>


void Init( void (*core0)( void * parameter ), void (*core1)( void * parameter ) )
{
    Serial.begin(115200);
    //Set the GPIO
    // pinMode(12, INPUT_PULLUP);//footswitch
    // pinMode(13, INPUT_PULLUP);//button
    // pinMode(32, INPUT_PULLUP);//toggle up
    // pinMode(33, INPUT_PULLUP);//toggle down
    // pinMode(25, OUTPUT); //led
    // pinMode(26,OUTPUT);//buttonled
    // pinMode(5, OUTPUT); //relay



    TaskHandle_t Task1, Task2;
  
    xTaskCreatePinnedToCore(
        core0,
        "Core0",
        1500,
        NULL,
        1,
        &Task1,
        0);
    delay(500);  // needed to start-up task1

    xTaskCreatePinnedToCore(
        core1,
        "Core1",
        1000,
        NULL,
        1,
        &Task2,
        1);

}
