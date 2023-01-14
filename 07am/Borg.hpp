#ifndef BORG_HPP_
#define BORG_HPP_

#include "AShip.hpp"
#include "Destination.hpp"
#include "Federation.hpp"
#include "WarpSystem.hpp"

namespace Borg
{
    class Ship : public AShip
    {
        public:
            Ship();
            Ship(int weaponFrequency, short repair);
            void checkCore() const;
            void fire(Federation::Ship *ship);
            void fire(Federation::Starfleet::Ship *ship);
            void repair();
            int getWeaponFrequency() const;
            short getRepair() const;
            void setWeaponFrequency(int weaponFrequency);
            void setRepair(short repair);
        private:
            int _weaponFrequency;
            short _repair;
    };
}

#endif