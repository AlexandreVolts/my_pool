#ifndef SICK_KOALA_LIST_H_
#define SICK_KOALA_LIST_H_

#include "AKoalaList.hpp"
#include "SickKoala.hpp"

class SickKoalaList : public AKoalaList<SickKoala *>
{
    public:
        SickKoalaList(SickKoala *koala);
        void append(SickKoala *koala);
        void dump() const;
        SickKoala *getFromName(std::string name) const;
        AKoalaList<SickKoala *> *removeFromName(std::string name);
};

#endif