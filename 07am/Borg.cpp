#include <iostream>
#include "Borg.hpp"

Borg::Ship::Ship() : _maxWarp(9), _core(nullptr), _home(UNICOMPLEX), _location(_home)
{
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}
void Borg::Ship::checkCore() const
{
    if (_core == nullptr)
        return;
    if (_core->checkReactor()->isStable()) {
        std::cout << "Everything is in order." << std::endl;
    }
    else {
        std::cout << "Critical failure imminent." << std::endl;
    }
}
bool Borg::Ship::move(int warp, Destination d)
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
bool Borg::Ship::move(int warp)
{
    return (move(warp, _home));
}
bool Borg::Ship::move(Destination d)
{
    return (move(0, d));
}
bool Borg::Ship::move()
{
    return (move(0, _home));
}