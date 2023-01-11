#ifndef A_KOALA_LIST_H_
#define A_KOALA_LIST_H_

#include "SickKoala.hpp"

template <class T>
class AKoalaList
{
    public:
        AKoalaList(T koala);
        bool isEnd() const;
        virtual void append(T koala) = 0;
        AKoalaList<T> *remove(AKoalaList<T> *koala);
        virtual void dump() const = 0;
        virtual T getFromName(std::string name) const = 0;
        T getContent() const;
        AKoalaList<T> *getNext() const;
    protected:
        void add(AKoalaList<T> *koala);
    private:
        T elem;
        AKoalaList<T> *next;
};

#endif