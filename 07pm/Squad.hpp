#ifndef SQUAD_HPP_
#define SQUAD_HPP_

#include <vector>
#include "Phaser.hpp"
#include "Skat.hpp"

class Squad
{
    public:
        Squad(int posXBegin, int posYBegin, Phaser::AmmoType type, int size = 5);
        void fire();
        void localisation() const;
        std::vector<Skat *> skats() const;
        Skat *at(int idx) const;
        int size() const;
    private:
        std::vector<Skat *> _skats;
};

#endif