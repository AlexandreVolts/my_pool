#include <iostream>
#include "Admiral.hpp"

Federation::Starfleet::Admiral::Admiral(std::string name) : _name(name)
{
    std::cout << "Admiral " << name << " ready for action." << std::endl;
}
void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
{
    std::cout << "On order from Admiral " << _name << ":" << std::endl;
    if (ship != nullptr)
        ship->fire(target);
}
bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship, Destination dest)
{
    if (ship == nullptr)
        return (false);
    return (ship->move(dest));
}