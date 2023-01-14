#ifndef ASHIP_HPP_
#define ASHIP_HPP_

#include "Destination.hpp"
#include "WarpSystem.hpp"

class AShip
{
    public:
        AShip(Destination d);
        virtual void setupCore(WarpSystem::Core *core);
        virtual void checkCore() const = 0;
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
        int getShield() const;
        void setShield(int shield);
    protected:
        WarpSystem::Core *_core;
        short _maxWarp;
        Destination _location;
        Destination _home;
        int _shield;
};

#endif