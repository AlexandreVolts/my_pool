#ifndef SICK_KOALA_LIST_H_
#define SICK_KOALA_LIST_H_

#include "AKoalaList.hpp"
#include "SickKoala.hpp"

class SickKoalaList : public AKoalaList<SickKoala *>
{
    public:
        SickKoalaList(SickKoala *koala);
};

#endif