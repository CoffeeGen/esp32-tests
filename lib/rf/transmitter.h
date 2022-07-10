#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <Arduino.h>
#include <SPI.h>
#include <RH_ASK.h>

class Transmitter 
{
    public:
        Transmitter( uint8_t pin, uint8_t baudrate );
        void transmit( const uint8_t *msg );
        bool success;

    private:
        uint8_t _pin;
        RH_ASK _driver;
};

#endif