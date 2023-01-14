#include <iostream>
#include "Borg.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair) :
AShip::AShip(UNICOMPLEX), _weaponFrequency(weaponFrequency), _repair(repair)
{
    _maxWarp = 9;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::Ship() : Borg::Ship::Ship(20, 3) {}

void Borg::Ship::checkCore() const
{
    if (_core == nullptr)
        return;
    if (_core->checkReactor()->isStable()) {
        std::cout << "Everything is in order." << std::endl;
    }
    else {
        std::cout << "Critical failure imminent." << std::endl;
    }
}
void Borg::Ship::fire(Federation::Ship *ship)
{
    WarpSystem::Core *core = ship->getCore();

    core->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
}
void Borg::Ship::fire(Federation::Starfleet::Ship *ship)
{
    ship->setShield(ship->getShield() - _weaponFrequency);
    std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
}
void Borg::Ship::repair()
{
    if (_repair <= 0) {
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
        return;
    }
    _repair--;
    _shield = 100;
    std::cout << "Begin shield re-initialisation... Done.";
    std::cout << " Awaiting further instructions." << std::endl;
}
int Borg::Ship::getWeaponFrequency() const
{
    return (_weaponFrequency);
}
short Borg::Ship::getRepair() const
{
    return (_repair);
}
void Borg::Ship::setWeaponFrequency(int weaponFrequency)
{
    _weaponFrequency = weaponFrequency;
}
void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}