#include <iostream>
#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial) :
_serial(serial) {}

void KoalaBot::setParts(const Arms &arms)
{
    _arms = arms;
}
void KoalaBot::setParts(const Legs &legs)
{
    _legs = legs;
}
void KoalaBot::setParts(const Head &head)
{
    _head = head;
}
void KoalaBot::swapParts(Arms &arms)
{
    swapParts(_arms, arms);
}
void KoalaBot::swapParts(Legs &legs)
{
    swapParts(_legs, legs);
}
void KoalaBot::swapParts(Head &head)
{
    swapParts(_head, head);
}
void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}
bool KoalaBot::status() const
{
    return (_arms.isFunctional() && _legs.isFunctional() && _head.isFunctional());
}
void KoalaBot::swapParts(Part &p1, Part &p2)
{
    Part tmp = p1;

    p1 = p2;
    p2 = tmp;
}