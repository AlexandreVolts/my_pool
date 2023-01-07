#include <fstream>
#include <iostream>
#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(size_t id) : isWorking(false)
{
    this->id = id;
}
KoalaNurse::~KoalaNurse()
{
    this->printId();
    std::cout << "Finally some rest!" << std::endl;
}
void KoalaNurse::giveDrug(std::string drug, const SickKoala &koala) const
{
    koala.takeDrug(drug);
}
std::string KoalaNurse::readReport(std::string report) const
{
    size_t index = report.find_last_of(".");
    std::string name;
    std::string drug;
    std::string output;
    std::ifstream file;

    if (index == std::string::npos || report.substr(index).compare(".report") != 0) {
        return ("");
    }
    file.open(report);
    if (!file.is_open())
        return ("");
    name = report.substr(0, index);
    for (char c = file.get(); c != -1; c = file.get()) {
        output += c;
    }
    this->printId();
    std::cout << "Kreog! Mr." << name << " needs a " << output << std::endl;
    return (output);
}
void KoalaNurse::timeCheck()
{
    this->printId();
    this->isWorking = !this->isWorking;
    if (this->isWorking) {
        std::cout << "Time to get to work!" << std::endl;
    }
    else {
        std::cout << "Time to go home to my eucalyptus forest!" << std::endl;
    }
}
void KoalaNurse::printId() const
{
    std::cout << "Nurse " << this->id << ": ";
}