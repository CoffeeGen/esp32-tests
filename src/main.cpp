#include <Arduino.h>
#include <init.h>
#include <globals.h>

#define echoPin         23 // 2
#define trigPin         22 // 3
#define greenLedPin     21 // 4
#define redLedPin       5  // 7
#define mqSensorPin     0 // A0
#define rfTxPin         13  // Pin of the 433MHz transmitter

#define rfTxBaudrate    ( uint8_t ) 2000 // Transmission Speed
#define LIGHTS_ON       ( const uint8_t* ) 262231
#define LIGHTS_OFF      ( const uint8_t* ) 262236

void Core0( void * parameter ) 
{
    for (;;) 
    {
        // vTaskDelay(10);
        delay( 2000 );
        Serial.println( "core0" );

        // Distance Sensor - Green Led
        int distance = uSensor->calcDistance();
        greenLed->trigger( distance < 5 );

        Serial.println( rfTx->success ? "rftx success" : "rftx failed" );

        if( distance > 5 )
        {
            Serial.println( "lights off" );
            rfTx->transmit( LIGHTS_OFF );
        }

        else
        {
            Serial.println( "lights on" );
            rfTx->transmit( LIGHTS_ON );
        }

        // Serial.print("Distance: ");
        // Serial.print(distance);
        // Serial.println(" cm | ");
    }
      
}
void Core1( void * parameter ) 
{
    for (;;) 
    {
        delay( 1000 );
        // Serial.println( "core1" );

        // // Smoke Sensor - Red Led
        // int smokeValue = mqSensor->value();
        // redLed->trigger( smokeValue > 1000 );

        // Serial.print("Smoke value: ");
        // Serial.println(smokeValue);

        // int distance = uSensor->calcDistance();
    }
      
}

void setup() {

    pinMode( echoPin, INPUT );
    pinMode( trigPin, OUTPUT );
    pinMode( mqSensorPin, OUTPUT );
    pinMode( greenLedPin, OUTPUT );
    pinMode( redLedPin, OUTPUT );
    pinMode( rfTxPin, OUTPUT );

    uSensor = new USensor( echoPin, trigPin );
    mqSensor = new MqSensor( mqSensorPin );

    // Leds
    greenLed = new Led( greenLedPin );
    redLed = new Led( redLedPin );

    rfTx = new Transmitter( rfTxPin, rfTxBaudrate );

    Init( Core0, Core1 );
}

void loop() {
}