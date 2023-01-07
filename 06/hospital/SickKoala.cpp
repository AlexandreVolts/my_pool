#include <iostream>
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}
SickKoala::~SickKoala()
{
    this->printName();
    std::cout << "Kreooogg!! I'm cuuuured!" << std::endl;
}
void SickKoala::poke() const
{
    this->printName();
    std::cout << "Gooeeeeerrk!!" << std::endl;
}
void SickKoala::takeDrug(const std::string drug) const
{
    this->printName();
    if (drug.compare("Mars") == 0) {
        std::cout << "Mars, and it kreogs!" << std::endl;
    }
    else if(drug.compare("Kinder") == 0) {
        std::cout << "There is a toy inside!" << std::endl;
    }
    else {
        std::cout << "Goerkreog!" << std::endl;
    }
}
void SickKoala::overDrive(std::string message) const
{
    this->printName();
    for (size_t i = message.find("Kreog!"); i != std::string::npos; i = message.find("Kreog!")) {
        message.replace(i, 6, "1337");
    }
    std::cout << message << std::endl;
}
std::string SickKoala::getName() const
{
    return (this->name);
}

void SickKoala::printName() const
{
    std::cout << "Mr." << this->name << ": ";
}