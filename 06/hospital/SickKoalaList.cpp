#include <iostream>
#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala) : AKoalaList(koala) {}

void SickKoalaList::append(SickKoala *koala)
{
    this->add(new SickKoalaList(koala));
}
void SickKoalaList::dump() const
{
    SickKoala *koala = this->getContent();

    std::cout << "Patients: ";
    if (koala != nullptr) {
        std::cout << koala->getName();
    }
    else {
        std::cout << "[nullptr]";
    }
    if (this->isEnd()) {
        std::cout << std::endl;
        return;
    }
    std::cout << ", ";
    this->getNext()->dump();
}
SickKoala *SickKoalaList::getFromName(std::string name) const
{
    SickKoala *koala = this->getContent();

    if (koala != nullptr && name.compare(koala->getName()) == 0) {
        return (koala);
    }
    if (this->isEnd()) {
        return (nullptr);
    }
    return (this->getNext()->getFromName(name));
}