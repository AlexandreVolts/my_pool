#ifndef BORG_HPP_
#define BORG_HPP_

#include "WarpSystem.hpp"

namespace Borg
{
    class Ship
    {
        public:
            Ship();
            virtual void setupCore(WarpSystem::Core *core);
            virtual void checkCore() const;
        protected:
            WarpSystem::Core *_core;
    };
}

#endif