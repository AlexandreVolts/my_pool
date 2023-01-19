#ifndef KREOG_COM_HPP_
#define KREOG_COM_HPP_

class KreogCom
{
    public:
        KreogCom(int x, int y, int serial); 
        ~KreogCom();
        void addCom(int x, int y, int serial);
        void ping() const;
        void locateSquad() const;
        void removeCom();
        KreogCom *getCom() const;
    private:
        const int _serial;
        const int _x;
        const int _y;
        KreogCom *_kc;
};

#endif
