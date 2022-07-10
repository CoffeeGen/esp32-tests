#include <usensor.h>

USensor::USensor( int echoPin, int trigPin ) :
    _trigPin( trigPin ),
    _echoPin( echoPin )
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int USensor::calcDistance()
{
    // Clears the trigPin condition
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    _duration = pulseIn(_echoPin, HIGH);
    // Calculating the distance
    _distance = _duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    
    if( _distance > 1000 )
        _distance = 0;
    
    // Displays the distance on the Serial Monitor

    return _distance;
}