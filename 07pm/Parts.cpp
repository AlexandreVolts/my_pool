#include <iostream>
#include "Parts.hpp"

Part::Part(const std::string partType, std::string serial, bool isFunctional) :
_partType(partType), _serial(serial), _functional(isFunctional) {}

bool Part::isFunctional() const
{
    return (_functional);
}
std::string Part::serial() const
{
    return (_serial);
}
void Part::informations() const
{
    std::cout << "\t[Parts] " << _partType << " ";
    std::cout << _serial << " status : ";
    std::cout << (_functional ? "OK" : "KO") << std::endl;
}
Part &Part::operator=(const Part &part)
{
    _serial = part.serial();
    _functional = part.isFunctional();
    return (*this);
}

Arms::Arms(std::string serial, bool functional) :
Part::Part("Arms", serial, functional) {}

Legs::Legs(std::string serial, bool functional) :
Part::Part("Legs", serial, functional) {}

Head::Head(std::string serial, bool functional) :
Part::Part("Head", serial, functional) {}