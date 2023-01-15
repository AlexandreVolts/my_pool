#include <iostream>
#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPack) :
_name(name), _stimPack(stimPack) {}

int &Skat::stimPack()
{
    return (_stimPack);
}
const std::string &Skat::name() const
{
    return (_name);
}
void Skat::shareStimPack(int number, int &stock)
{
    if (number > _stimPack) {
        std::cout << "Don't be greedy." << std::endl;
        return;
    }
    _stimPack -= number;
    stock += number;
    std::cout << "Keep the change." << std::endl;
}
void Skat::addStimPack(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
    }
    _stimPack += number;
}
void Skat::useStimPack()
{
    if (_stimPack == 0) {
        std::cout << "Mediiiiiic" << std::endl;
        return;
    }
    _stimPack--;
    std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
}
void Skat::status() const
{
    std::cout << "Soldier " << _name << " reporting ";
    std::cout << _stimPack << " stimpaks remaining sir!" << std::endl;
}