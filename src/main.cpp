#include <iostream>
#include <cstdlib>
#include <string>

#include "greeter.pb.h"

using greeter::Greeting;

namespace
{

    std::string create_greeting(std::string const & whom)
    {
        Greeting greeting;
        greeting.set_whom("Bob");

        return greeting.SerializeAsString();
    }

    Greeting deserialize(std::string const & message)
    {
        Greeting greeting;
        greeting.ParseFromString(message);

        return greeting;
    }

}

int main(int argc, char * argv[])
{
    std::string message = create_greeting("Bob");
    Greeting greeting = deserialize(message);

    std::cout << "Hello, " << greeting.whom() << "!" << std::endl;
    return EXIT_SUCCESS;
}