#include <transmitter.h>

Transmitter::Transmitter( int pin, int baudrate ) :
    _pin( pin ),
    success( false )
{   
    if( _driver.init( ) )
    {
        Serial.println( "RF433MHZ Transmitter Driver initialization success!" );
        success = true;
    }
}

void Transmitter::transmit( const char* message ) 
{
    _driver.send( (uint8_t *) message, strlen(message) );
    _driver.waitPacketSent();
    Serial.println("message sent!");
}