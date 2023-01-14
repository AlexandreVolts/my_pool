#include "BorgQueen.hpp"

bool Borg::BorgQueen::move(Borg::Ship *ship, Destination dest)
{
    if (ship == nullptr)
        return (false);
    return (ship->move(dest));
}
void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target)
{
    if (ship != nullptr)
        ship->fire(target);
}
void destroy(Borg::Ship *ship, Federation::Ship *target)
{
    if (ship != nullptr)
        ship->fire(target);
}