#ifndef KOALA_NURSE_HPP_
#define KOALA_NURSE_HPP_

#include <stdlib.h>
#include <string>
#include "SickKoala.hpp"

class KoalaNurse
{
    public:
        KoalaNurse(size_t id);
        ~KoalaNurse();
        void giveDrug(std::string drug, const SickKoala &koala) const;
        std::string readReport(std::string report) const;
        void timeCheck();
    private:
        size_t id;
        bool isWorking;
        void printId() const;
};

#endif