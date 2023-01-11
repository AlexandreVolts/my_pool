#ifndef DOCTOR_KOALA_HPP_
#define DOCTOR_KOALA_HPP_

#include <string>
#include "SickKoala.hpp"

class KoalaDoctor
{
    public:
        KoalaDoctor(std::string name);
        void diagnose(SickKoala *koala) const;
        void timeCheck();
        const std::string &getName() const;
    private:
        std::string name;
        bool isWorking;
        void printName() const;
};

#endif