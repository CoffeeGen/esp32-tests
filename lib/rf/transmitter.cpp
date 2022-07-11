#include <transmitter.h>

Transmitter::Transmitter( int pin, int pulseLength ) :
    _pin( pin ),
    success( false )
{   
    _switch.enableTransmit(pin);
    _switch.setProtocol( 0, 326 );
  
    _switch.setRepeatTransmit(30);

    // set pulse length.
    _switch.setPulseLength(pulseLength);
}

void Transmitter::transmit( unsigned long code ) 
{
    _switch.send( code, 24);
    Serial.println("message sent!");
}