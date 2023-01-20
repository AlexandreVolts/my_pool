#ifndef PHASER_HPP_
#define PHASER_HPP_

#include <map>

class Phaser
{
    public:
        enum AmmoType
        {
            REGULAR,
            PLASMA,
            ROCKET
        };
        Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        void fire();
        void ejectClip();
        void changeType(AmmoType type);
        void reload();
        int getCurrentAmmos() const;
    private:
        void playSound() const;
        static const int Empty = 0;
        const int _maxAmmo;
        std::map<AmmoType, int> _magazine;
        AmmoType _type;
};

#endif