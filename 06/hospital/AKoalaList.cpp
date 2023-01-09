#include "AKoalaList.hpp"

template <class T>
AKoalaList<T>::AKoalaList(T koala)
{
    this->elem = koala;
    this->next = nullptr;
}
template <class T>
void AKoalaList<T>::append(T koala)
{
    if (this->next == nullptr) {
        this->next = new AKoalaList(koala);
        return;
    }
    this->next->append(koala);
}
template <class T>
bool AKoalaList<T>::isEnd() const
{
    return (this->next == nullptr);
}
template <class T>
AKoalaList<T> *AKoalaList<T>::remove(T koala)
{
    if (this->elem == koala) {
        return (this->next);
    }
    if (this->next->getCurrent() == koala) {
        this->next = this->next == nullptr ? nullptr : this->next->getNext();
        delete this->next;
        return (this);
    }
    if (!this->isEnd())
        this->next->remove(koala);
    return (this);
}
template <class T>
T AKoalaList<T>::getCurrent() const
{
    return (this->elem);
}
template <class T>
AKoalaList<T> *AKoalaList<T>::getNext() const
{
    return (this->next);
}

template class AKoalaList<SickKoala *>;