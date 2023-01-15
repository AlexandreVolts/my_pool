#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <string>

class Skat
{
    public:
        Skat(const std::string &name = "bob", int stimPack = 15);
        int &stimPack();
        const std::string &name() const;
        void shareStimPack(int number, int &stock);
        void addStimPack(unsigned int number);
        void useStimPack();
        void status() const;
    private:
        const std::string &_name;
        int _stimPack;
};

#endif