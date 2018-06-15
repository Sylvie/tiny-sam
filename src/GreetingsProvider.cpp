#include <string>
#include <iostream>
#include <fstream>
#include "GreetingsProvider.hpp"

std::string GreetingsProvider::sayHelloWorld() const {
    return "Hello World !";
}

void GreetingsProvider::writeHelloWorld() const {
    std::string filename("hello.txt");
    std::ofstream output(filename);

    std::cout << "Yop!" << std::endl;
    if (output.is_open())
    {
        std::cout << "Let's write!" << std::endl;
        output << sayHelloWorld() << std::endl;
        output.close();
    }
    else
    {
        std::cerr << "Could not create file!" << std::endl;
    }
}
