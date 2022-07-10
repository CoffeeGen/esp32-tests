#include <transmitter.h>

Transmitter::Transmitter( uint8_t pin, uint8_t baudrate ) :
    _manager( _driver, 4 ),
    _pin( pin ),
    success( false )
{   
    if( _manager.init( ) )
    {
        Serial.println( "RF433MHZ Transmitter Driver initialization success!" );
        success = true;

        _manager.addRouteTo(1, 1);
    }
}

void Transmitter::transmit( uint8_t data[] ) 
{
    if(_manager.sendtoWait( data, sizeof( data ), 326) != RH_ROUTER_ERROR_NONE)
        Serial.println("sendtoWait failed");
}