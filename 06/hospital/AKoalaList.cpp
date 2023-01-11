#include "AKoalaList.hpp"

template <class T>
AKoalaList<T>::AKoalaList(T koala)
{
    this->elem = koala;
    this->next = nullptr;
}
template <class T>
bool AKoalaList<T>::isEnd() const
{
    return (this->next == nullptr);
}
template <class T>
AKoalaList<T> *AKoalaList<T>::remove(AKoalaList<T> *koala)
{
    if (this == koala) {
        return (this->next);
    }
    if (this->next == koala) {
        this->next = this->next == nullptr ? nullptr : this->next->getNext();
        delete this->next;
        return (this);
    }
    if (!this->isEnd())
        this->next->remove(koala);
    return (this);
}
template <class T>
T AKoalaList<T>::getContent() const
{
    return (this->elem);
}
template <class T>
AKoalaList<T> *AKoalaList<T>::getNext() const
{
    return (this->next);
}

template <class T>
void AKoalaList<T>::add(AKoalaList<T> *koala)
{
    if (this->next == nullptr) {
        this->next = koala;
        return;
    }
    this->next->add(koala);
}

template class AKoalaList<SickKoala *>;