#ifndef KOALA_NURSE_HPP_
#define KOALA_NURSE_HPP_

#include <stdlib.h>
#include <string>
#include "SickKoala.hpp"

class KoalaNurse
{
    public:
        KoalaNurse(int id);
        ~KoalaNurse();
        void giveDrug(std::string drug, const SickKoala &koala) const;
        std::string readReport(std::string report) const;
        void timeCheck();
        int getID() const;
    private:
        int id;
        bool isWorking;
        void printId() const;
};

#endif