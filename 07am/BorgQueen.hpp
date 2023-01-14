#ifndef BORG_QUEEN_HPP_
#define BORG_QUEEN_HPP_

#include "Borg.hpp"
#include "Federation.hpp"

namespace Borg
{
    class BorgQueen
    {
        bool move(Borg::Ship *ship, Destination dest);
        void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
        void destroy(Borg::Ship *ship, Federation::Ship *target);
    };
}

#endif