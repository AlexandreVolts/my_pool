#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include "Borg.hpp"
#include "WarpSystem.hpp"

namespace Federation
{
    class Ship : Borg::Ship
    {
        public:
            Ship(int length, int width, std::string name);
            virtual void setupCore(WarpSystem::Core *core);
            virtual void checkCore() const;
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
        class Ship : Federation::Ship
        {
            public:
                Ship(int length, int width, std::string name, short maxWarp);
                void setupCore(WarpSystem::Core *core);
                void checkCore() const;
                void promote(Starfleet::Captain *captain);
            private:
                short _maxWarp;
                Starfleet::Captain *_captain;
        };
    }
}

#endif