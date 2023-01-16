#ifndef KOALA_BOT_HPP_
#define KOALA_BOT_HPP_

#include "Parts.hpp"

class KoalaBot
{
    public:
        KoalaBot(std::string serial = "Bob-01");
        void setParts(const Arms &arms);
        void setParts(const Legs &legs);
        void setParts(const Head &head);
        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void swapParts(Head &head);
        void informations() const;
        bool status() const;
    private:
        void swapParts(Part &p1, Part &p2);
        std::string _serial;
        Arms _arms;
        Legs _legs;
        Head _head;
};

#endif