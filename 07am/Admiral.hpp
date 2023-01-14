#ifndef ADMIRAL_HPP_
#define ADMIRAL_HPP_

#include <string>
#include "Destination.hpp"
#include "Federation.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Admiral
        {
            public:
                Admiral(std::string name);
                void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
                bool move(Federation::Starfleet::Ship *ship, Destination dest);
            private:
                std::string _name;
        };
    }
}

#endif