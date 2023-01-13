#ifndef BORG_HPP_
#define BORG_HPP_

#include "Destination.hpp"
#include "WarpSystem.hpp"

namespace Borg
{
    class Ship
    {
        public:
            Ship();
            virtual void setupCore(WarpSystem::Core *core);
            virtual void checkCore() const;
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
        protected:
            WarpSystem::Core *_core;
            short _maxWarp;
            Destination _location;
            Destination _home;
    };
}

#endif