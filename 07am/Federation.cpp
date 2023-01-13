#include <iostream>
#include "Federation.hpp"

Federation::Ship::Ship(int length, int width, std::string name) :
_length(length), _width(width), _name(name) {
    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m long and " << width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    std::cout << _name << ": The core is set." << std::endl;
    _core = core;
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

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp) :
Federation::Ship::Ship(length, width, name), _maxWarp(maxWarp)
{
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    std::cout << "USS. ";
    Federation::Ship::setupCore(core);
}
void Federation::Starfleet::Ship::checkCore() const
{
    std::cout << "USS. ";
    Federation::Ship::checkCore();
}