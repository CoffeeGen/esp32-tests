#include <Arduino.h>
#include <init.h>
#include <globals.h>


#define echoPin         4 // 2
#define trigPin         22 // 3
#define greenLedPin     21 // 4
#define redLedPin       5  // 7
#define mqSensorPin     0 // A0
#define rfTxPin         23  // Pin of the 433MHz transmitter
#define btnPin          15
#define servoPin        14

#define rfTxBaudrate    326 // Transmission Speed
#define LIGHTS_ON       262231
#define LIGHTS_OFF      262236

void Core0( void * parameter ) 
{
    for (;;) 
    {
        // vTaskDelay(10);
        delay( 50 );
        Serial.println( "core0" );



        // Serial.println( rfTx->success ? "rftx success" : "rftx failed" );

        // if( distance > 5 )
        // {
        //     Serial.println( "lights off" );
        //     rfTx->transmit( 262236 );
        // }

        // else
        // {
        //     Serial.println( "lights on" );
        //     rfTx->transmit( 262231 );
        // }

        int state = digitalRead( btnPin );

        if( state == HIGH )
        {
            switch( lightState )
            {
                case Off:
                    rfTx->transmit( 262231 );
                    lightState = On;
                    Serial.println( "lights on" );
                    break;

                case On:
                    rfTx->transmit( 262236 );
                    lightState = Off;
                    Serial.println( "lights off" );
                    break;
            }

            redLed->trigger( lightState == Off );
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
        delay( 50 );
        Serial.println( "core1" );

        // Distance Sensor - Green Led
        int distance = uSensor->calcDistance();
        greenLed->trigger( distance < 5 );

        // for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
        //     servo.write(posDegrees);
        //     Serial.println(posDegrees);
        //     delay(20);
        // }

        // for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
        //     servo.write(posDegrees);
        //     Serial.println(posDegrees);
        //     delay(20);
        // }

        // int state = digitalRead( btnPin );

        // if( state == HIGH )
        // {
        //     switch( lightState )
        //     {
        //         case Off:
        //             rfTx->transmit( 262231 );
        //             lightState = On;
        //             Serial.println( "lights on" );
        //             break;

        //         case On:
        //             rfTx->transmit( 262236 );
        //             lightState = Off;
        //             Serial.println( "lights off" );
        //             break;
        //     }
        // }

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
    // pinMode( mqSensorPin, OUTPUT );
    pinMode( greenLedPin, OUTPUT );
    pinMode( redLedPin, OUTPUT );
    pinMode( rfTxPin, OUTPUT );
    pinMode(btnPin, INPUT);
    pinMode( servoPin, OUTPUT );

    lightState = Off;

    rfTx = new Transmitter( rfTxPin, 326 );
    rfTx->transmit( 262236 );

    uSensor = new USensor( echoPin, trigPin );
    mqSensor = new MqSensor( mqSensorPin );

    // Leds
    greenLed = new Led( greenLedPin );
    redLed = new Led( redLedPin );

    // Turn on when room lights are off
    redLed->trigger( lightState == Off );

    // servo.attach(
    //     servoPin, 
    //     Servo::CHANNEL_NOT_ATTACHED, 
    //     45,
    //     120
    // );

    Init( Core0, Core1 );
}

void loop() {
}