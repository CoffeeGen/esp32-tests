#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <Arduino.h>
#include <RH_E32.h>
#include "SoftwareSerial.h"
#include <SPI.h>

class Transmitter 
{
    public:
        Transmitter( uint8_t pin, uint8_t baudrate );
        void transmit( uint8_t data[] );
        bool success;

    private:
        uint8_t _pin;
        RH_E32  _driver;
        SoftwareSerial _serial;
};

#endif