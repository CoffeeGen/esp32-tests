#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <Arduino.h>
#include <RCSwitch.h>

class Transmitter 
{
    public:
        Transmitter( int pin, int pulseLength );
        void transmit( unsigned long code );
        bool success;

    private:
        int _pin;
        RCSwitch  _switch;
};

#endif