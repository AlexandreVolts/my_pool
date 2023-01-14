#include <iostream>
#include "Federation.hpp"
#include "Borg.hpp"

Federation::Ship::Ship(int length, int width, std::string name) :
AShip::AShip(VULCAN), _length(length), _width(width), _name(name) {
    _maxWarp = 1;
    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m long and " << width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    std::cout << _name << ": The core is set." << std::endl;
    AShip::setupCore(core);
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
WarpSystem::Core *Federation::Ship::getCore() const
{
    return (_core);
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

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo) :
Federation::Ship::Ship(length, width, name), _photonTorpedo(torpedo), _captain(nullptr)
{
    _home = EARTH;
    _location = EARTH;
    _maxWarp = maxWarp;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
    if (torpedo != 0) {
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
    }
}
Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp) :
Federation::Starfleet::Ship::Ship(length, width, name, maxWarp, 0) {}

Federation::Starfleet::Ship::Ship() :
Federation::Starfleet::Ship::Ship(289, 132, "Entreprise", 6) {};

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
void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (_captain == nullptr)
        return;
    if (_photonTorpedo - torpedoes < 0) {
        std::cout << "USS. " << _name << ": Not enough torpedoes to fire, ";
        std::cout << _captain->getName() << "!" << std::endl;
        return;
    }
    _photonTorpedo -= torpedoes;
    target->setShield(target->getShield() - torpedoes * 50);
    std::cout << "USS. " << _name << ": Firing on target. ";
    std::cout << _photonTorpedo << " torpedoes remaining." << std::endl;
    if (_photonTorpedo == 0) {
        std::cout << "USS. " << _name << ": No more torpedoes to fire, ";
        std::cout << _captain->getName() << "!" << std::endl;
    }
}
void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    fire(1, target);
}
int Federation::Starfleet::Ship::getTorpedo() const
{
    return (_photonTorpedo);
}
void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}