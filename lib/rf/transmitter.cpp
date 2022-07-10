#include <transmitter.h>

Transmitter::Transmitter( uint8_t pin, uint8_t baudrate ) :
    _driver( baudrate, -1, _pin ),
    _pin( pin ),
    success( true )
{   
    if( !_driver.init( ) )
    {
        Serial.println( "RF433MHZ Transmitter Driver initialization failed!" );
        success = false;
    }
}

void Transmitter::transmit( const uint8_t *msg ) 
{
    _driver.send( msg, 6 );
    _driver.waitPacketSent();
}