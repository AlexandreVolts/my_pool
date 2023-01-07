#ifndef SICK_KOALA_HPP_
#define SICK_KOALA_HPP_

#include <string>

class SickKoala
{
    public:
        SickKoala(std::string name);
        ~SickKoala();
        void poke() const;
        void takeDrug(const std::string drug) const;
        void overDrive(std::string message) const;
        std::string getName() const;
    private:
        void printName() const;
        std::string name;
};

#endif