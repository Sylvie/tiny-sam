#include <string>

class GreetingsProvider
{
public:
    virtual std::string sayHelloWorld() const;
    virtual void writeHelloWorld() const;
};
