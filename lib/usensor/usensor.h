#ifndef USENSOR_H
#define USENSOR_H

#include "Arduino.h"

class USensor 
{
    public:
        USensor( int echoPin, int trigPin );
        int calcDistance();

    private:
        long _duration;
        int _distance, _trigPin, _echoPin;
};

#endif