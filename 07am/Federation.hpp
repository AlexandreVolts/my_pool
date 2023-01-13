#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include "WarpSystem.hpp"

namespace Federation
{
    class Ship
    {
        public:
            Ship(int length, int width, std::string name);
            virtual void setupCore(WarpSystem::Core *core);
            virtual void checkCore() const;
        private:
            int _length;
            int _width;
            std::string _name;
            WarpSystem::Core *_core;
    };
    namespace Starfleet
    {
        class Ship : Federation::Ship
        {
            public:
                Ship(int length, int width, std::string name, short maxWarp);
                void setupCore(WarpSystem::Core *core);
                void checkCore() const;
            private:
                short _maxWarp;
        };
    }
}

#endif