#include <iostream>
#include <string>
#include "GreetingsProvider.hpp"

int main(int argc, char** argv)
{
	GreetingsProvider greetingsProvider = GreetingsProvider();
	std::cout << greetingsProvider.sayHelloWorld() << std::endl;
	std::cout << "C++ version: " <<  __cplusplus << std::endl;
	greetingsProvider.writeHelloWorld();
}
