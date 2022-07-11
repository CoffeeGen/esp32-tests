#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

class Transmitter 
{
    public:
        Transmitter( int pin, int baudrate );
        void transmit( const char* message );
        bool success;

    private:
        int _pin;
        RH_ASK  _driver;
};

#endif