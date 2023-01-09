#ifndef A_KOALA_LIST_H_
#define A_KOALA_LIST_H_

#include "SickKoala.hpp"

template <class T>
class AKoalaList
{
    public:
        AKoalaList(T koala);
        void append(T koala);
        bool isEnd() const;
        AKoalaList<T> *remove(T koala);
        //virtual void dump() const;
        T getCurrent() const;
        AKoalaList<T> *getNext() const;
    protected:
        //virtual void get(void *id) const;
        //virtual void removeFrom(void *id);
    private:
        T elem;
        AKoalaList<T> *next;
};

#endif