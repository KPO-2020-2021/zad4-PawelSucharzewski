#pragma once
#include "Wielokat.h"

const int SCIANY = 6;

class Prostopadloscian {
private:
    std::array<Wielokat<KWADRAT>, SCIANY> sciany;
    std::string kolor;
public:
    Prostopadloscian() = default;
    Prostopadloscian(double dlugosc, double wysokosc, double szerokosc, std::string color = KOLOR);

    void rysuj();

    void obrot(double kat, char os);

    void obrot(MacierzObrotu<STANDARD> obrotu);

    void translacja(double x, double y, double z);

    const Wielokat<KWADRAT> & operator[](int index) const;
    Wielokat<KWADRAT> & operator[](int index);

};

std::ostream & operator<<(std::ostream & ost, const Prostopadloscian &pro);
