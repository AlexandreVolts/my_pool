#include <iostream>
#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) :
_x(x), _y(y), _serial(serial), _kc(nullptr)
{
    std::cout << "KreogCom " << _serial << " initialized" << std::endl;
}
KreogCom::~KreogCom()
{
    KreogCom *tmp;

    while (_kc != nullptr) {
        removeCom();
    }
    std::cout << "KreogCom " << _serial << " shutting down" << std::endl;
}
void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *kc = _kc;

    _kc = new KreogCom(x, y, serial);
    _kc->_kc = kc;
}
void KreogCom::ping() const
{
    std::cout << "KreogCom " << _serial << " currently at ";
    std::cout << _x << " " << _y << std::endl;
}
void KreogCom::locateSquad() const
{
    if (_kc != nullptr) {
        _kc->locateSquad();
    }
    ping();
}
void KreogCom::removeCom()
{
    KreogCom *kc = _kc->getCom();

    delete _kc;
    _kc = kc;
}
KreogCom *KreogCom::getCom() const
{
    return (_kc);
}