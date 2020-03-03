#include "GELF.hpp"

#include <iostream>
#include <string>

int main( int argc, char** argv )
{
    gelf::initialize();
    gelf::configure( "192.168.0.7", 12202 );

    gelf::MessageBuilder message( gelf::Severity::Informational, "Hello world!" );
		message.fullMessage( "Full message" );
	    message.fileName( "main.cpp" );
	    message.lineNumber( 25 );
	    message.setHost( "192.168.0.7" );

	gelf::Message m = message.build();

std::cout << gelf::getConfiguredPort() << std::endl;

	std::cout << m.getMessage() << std::endl;

    gelf::post( m, "192.168.0.7", 12201 );

    gelf::destroy();

    return 0;
}
