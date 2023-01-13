#include <iostream>
#include "Borg.hpp"

Borg::Ship::Ship()
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