#include <led.h>

Led::Led( int ledPin ) :
    _ledPin( ledPin )
{
    pinMode(_ledPin, OUTPUT);
}

void Led::trigger( bool toggle ) 
{
    digitalWrite(_ledPin, toggle ? HIGH : LOW );
}