#include <mqsensor.h>

MqSensor::MqSensor( uint8_t sensorPin ) :
    _sensorPin( sensorPin )
{
}

int MqSensor::value( ) 
{
    int sensorValue = analogRead( _sensorPin );
    
    return sensorValue;
}