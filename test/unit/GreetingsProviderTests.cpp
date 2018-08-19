#include "catch.hpp"
#include "GreetingsProvider.hpp"

TEST_CASE( "Hello World" )
{
	GreetingsProvider greetingsProvider = GreetingsProvider();
	
	SECTION( "Hello World is provided" )
	{
		REQUIRE( greetingsProvider.sayHelloWorld() == "Hello World !" );
	}
	
	SECTION( "Hello World has the right length" )
	{
		REQUIRE( greetingsProvider.sayHelloWorld().size() == 13 );
	}
	
}
