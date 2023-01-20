#include <string>
#include "Squad.hpp"

Squad::Squad(int posXBegin, int posYBegin, Phaser::AmmoType type, int size)
{
    int i = 0;

    for (; i < size; i++) {
        _skats.push_back(new Skat(std::to_string(i), 10, i, posXBegin, posYBegin, type));
        posXBegin += 10;
        posYBegin += 15;
        if (i > 0) {
            _skats.at(i - 1)->com().addCom(&_skats.at(i)->com());
        }
    }
    _skats.at(i - 1)->com().addCom(&_skats.at(i)->com());
}
void Squad::fire()
{
    for (Skat *skat : _skats) {
        skat->fire();
    }
}
void Squad::localisation() const
{
    for (Skat *skat : _skats) {
        skat->locate();
    }
}
std::vector<Skat *> Squad::skats() const
{
    return _skats;
}
Skat *Squad::at(int idx) const
{
    return (_skats.at(idx));
}
int Squad::size() const
{
    return (_skats.size());
}