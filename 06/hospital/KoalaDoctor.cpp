#include <fstream>
#include <list>
#include <iostream>
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name) : isWorking(false)
{
    this->name = name;
    this->printName();
    std::cout << "I'm Dr." << name << "! How do you kreog?" << std::endl;
}

void KoalaDoctor::diagnose(SickKoala *koala) const
{
    std::string name = koala->getName();
    std::ofstream report(name + ".report");
    std::list<std::string> drugs = { "Mars", "Kinder", "Maroille", "Crunch", "Eucalyptus leaf" };

    this->printName();
    std::cout << "So what's goerking you Mr." << name << "?" << std::endl;
    koala->poke();
    for (size_t i = rand() % drugs.size(); i > 0; i--) {
        drugs.pop_back();
    }
    report << drugs.back();
    report.close();
}
void KoalaDoctor::timeCheck()
{
    this->printName();
    this->isWorking = !this->isWorking;
    if (this->isWorking) {
        std::cout << "Time to get to work!" << std::endl;
    }
    else {
        std::cout << "Time to go home to my eucalyptus forest!" << std::endl;
    }
}
const std::string &KoalaDoctor::getName() const
{
    return (this->name);
}
void KoalaDoctor::printName() const
{
    std::cout << "Dr." << this->name << ": ";
}