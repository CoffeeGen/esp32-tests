#include <transmitter.h>

Transmitter::Transmitter( uint8_t pin, uint8_t baudrate ) :
    _serial( 7, 6 ),
    _driver( &_serial, 4, 5, 8 ),
    _pin( pin ),
    success( false )
{   
    _serial.begin(115200); 

    if( _driver.init( ) )
    {
        Serial.println( "RF433MHZ Transmitter Driver initialization success!" );
        success = true;
    }
}

void Transmitter::transmit( uint8_t data[] ) 
{
    if( _driver.available() )
    {
        _driver.send( data, sizeof(data) );
        _driver.waitPacketSent();
        Serial.println("message sent!");
    }
}