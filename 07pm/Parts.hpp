#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <string>

class Part
{
    public:
        Part(const std::string partType, std::string serial, bool functional);
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
        Part &operator=(const Part &part);
    protected:
        const std::string _partType;
    private:
        std::string _serial;
        bool _functional;
};
class Arms : public Part
{
    public:
        Arms(std::string serial = "A-01", bool functional = true);
};
class Legs : public Part
{
    public:
        Legs(std::string serial = "L-01", bool functional = true);
};
class Head : public Part
{
    public:
        Head(std::string serial = "H-01", bool functional = true);
};

#endif