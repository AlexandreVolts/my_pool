#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include "AShip.hpp"
#include "WarpSystem.hpp"

namespace Borg {
    class Ship;
}
namespace Federation
{
    class Ship : public AShip
    {
        public:
            Ship(int length, int width, std::string name);
            virtual void setupCore(WarpSystem::Core *core);
            virtual void checkCore() const;
            WarpSystem::Core *getCore() const;
        protected:
            std::string _name;
        private:
            int _length;
            int _width;
    };
    namespace Starfleet
    {
        class Ensign
        {
            Ensign(std::string name);
        };
        class Captain
        {
            public:
                Captain(std::string name);
                std::string getName() const;
                int getAge() const;
                void setAge(int age);
            private:
                std::string _name;
                int _age;
        };
        class Ship : public Federation::Ship
        {
            public:
                Ship(int length, int width, std::string name, short maxWarp, int torpendo);
                Ship(int length, int width, std::string name, short maxWarp);
                Ship();
                void setupCore(WarpSystem::Core *core);
                void checkCore() const;
                void promote(Starfleet::Captain *captain);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);
                int getTorpedo() const;
                void setTorpedo(int torpedo);
            private:
                Starfleet::Captain *_captain;
                int _photonTorpedo;
        };
    }
}

#endif