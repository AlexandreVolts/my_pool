#include <iostream>
#include "Phaser.hpp"
#include "Sounds.hpp"

Phaser::Phaser(int maxAmmo, AmmoType type)
: _maxAmmo(maxAmmo), _type(type) {
    _magazine[REGULAR] = 0;
    _magazine[PLASMA] = 0;
    _magazine[ROCKET] = 0;
    _magazine[type] = maxAmmo;
}

void Phaser::fire()
{
    Sounds sounds;

    if (_magazine[_type] == 0) {
        std::cout << "Clip empty, please reload." << std::endl;
        return;
    }
    playSound();
    _magazine[_type]--;
}
void Phaser::ejectClip()
{
    _magazine[_type] = Empty;
}
void Phaser::changeType(AmmoType type)
{
    Sounds sounds;

    _type = type;
    std::cout << "Switching ammo to type: ";
    playSound();
}
void Phaser::reload()
{
    if (_magazine[_type] == _maxAmmo) {
        std::cout << "Clip full" << std::endl;
        return;
    }
    _magazine[_type] = _maxAmmo;
    std::cout << "Reloading..." << std::endl;
}
int Phaser::getCurrentAmmos() const
{
    return (_magazine.at(_type));
}
void Phaser::playSound() const
{
    Sounds sounds;

    switch (_type) {
        case REGULAR:
            std::cout << sounds.Regular << std::endl;
            break;
        case PLASMA:
            std::cout << sounds.Plasma << std::endl;
            break;
        case ROCKET:
            std::cout << sounds.Rocket << std::endl;
            break;
    }
}