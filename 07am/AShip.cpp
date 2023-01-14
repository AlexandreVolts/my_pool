#include <iostream>
#include "AShip.hpp"

AShip::AShip(Destination home) :
_home(home), _location(home), _core(nullptr), _shield(100) {}

void AShip::setupCore(WarpSystem::Core *core)
{
    _core = core;
}
bool AShip::move(int warp, Destination d)
{
    if (warp > _maxWarp || d == _location || _core == nullptr) {
        return (false);
    }
    if (!_core->checkReactor()->isStable()) {
        return (false);
    }
    _location = d;
    return (true);
}
bool AShip::move(int warp)
{
    return (move(warp, _home));
}
bool AShip::move(Destination d)
{
    return (move(0, d));
}
bool AShip::move()
{
    return (move(0, _home));
}
int AShip::getShield() const
{
    return (_shield);
}
void AShip::setShield(int shield)
{
    _shield = shield;
}