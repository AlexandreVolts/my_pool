#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <string>
#include "KreogCom.hpp"
#include "Phaser.hpp"

class Skat
{
    public:
        Skat(const std::string &name, int stimPack, int serial, int x, int y, Phaser::AmmoType type);
        int &stimPack();
        const std::string &name() const;
        void shareStimPack(int number, int &stock);
        void addStimPack(unsigned int number);
        void useStimPack();
        void status() const;
        void fire();
        void reload();
        void locate() const;
        KreogCom &com();
    private:
        const std::string &_name;
        int _stimPack;
        Phaser _phaser;
        KreogCom _com;
};

#endif