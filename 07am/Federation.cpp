#include <iostream>
#include "Federation.hpp"
#include "Borg.hpp"

Federation::Ship::Ship(int length, int width, std::string name) :
_length(length), _width(width), _name(name) {
    _home = VULCAN;
    _location = _home;
    _maxWarp = 1;
    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m long and " << width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    std::cout << _name << ": The core is set." << std::endl;
    Borg::Ship::setupCore(core);
}
void Federation::Ship::checkCore() const
{
    bool isStable = false;
    
    if (_core == nullptr)
        return;
    isStable = _core->checkReactor()->isStable();
    std::cout << _name << ": The core is ";
    std::cout << (isStable ? "stable" : "unstable") << " at the time." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}
Federation::Starfleet::Captain::Captain(std::string name) : _name(name), _age(0) {}

std::string Federation::Starfleet::Captain::getName() const
{
    return (_name);
}
int Federation::Starfleet::Captain::getAge() const
{
    return (_age);
}
void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp) :
Federation::Ship::Ship(length, width, name), _captain(nullptr)
{
    _home = EARTH;
    _location = EARTH;
    _maxWarp = maxWarp;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    std::cout << "USS. ";
    Federation::Ship::setupCore(core);
}
void Federation::Starfleet::Ship::checkCore() const
{
    if (_core == nullptr)
        return;
    std::cout << "USS. ";
    Federation::Ship::checkCore();
}
void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    _captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS ";
    std::cout << _name << "." << std::endl;
}