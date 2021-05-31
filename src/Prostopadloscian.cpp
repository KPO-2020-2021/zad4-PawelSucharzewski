#include "Prostopadloscian.h"

Prostopadloscian::Prostopadloscian(double dlugosc, double wysokosc, double szerokosc, std::string _kolor) {
    Wektor<STANDARD> v({dlugosc, 0, 0});
    Wektor<STANDARD> r({0, wysokosc, 0});
    Wektor<STANDARD> w({0, 0, szerokosc});

    sciany[0] = Wielokat<KWADRAT>(v, w);
    sciany[1] = Wielokat<KWADRAT>(w, v, r);
    sciany[2] = Wielokat<KWADRAT>(r, w);
    sciany[3] = Wielokat<KWADRAT>(r, v, w);
    sciany[4] = Wielokat<KWADRAT>(r, w, v);
    sciany[5] = Wielokat<KWADRAT>(r, v);
    translacja(-1 * dlugosc / 2, -1 * wysokosc / 2, -1 * szerokosc / 2);
    kolor = _kolor;
}

void Prostopadloscian::rysuj() {
    for (int i = 0; i < SCIANY; ++i) {
        sciany[i].rysuj();
    }
}

void Prostopadloscian::obrot(double kat, char os) {
    for (int i = 0; i < SCIANY; ++i) {
        sciany[i].obrot(kat, os);
    }
}

void Prostopadloscian::translacja(double x, double y, double z) {
    Wektor<STANDARD> wektor({x, y ,z});
    for (int i = 0; i < SCIANY; ++i) {
        sciany[i].translacja(wektor);
    }
}

const Wielokat<KWADRAT> &Prostopadloscian::operator[](int index) const {
    if (index > SCIANY || index < 0) throw std::invalid_argument("Nieprawidlowy index!");
    return sciany[index];
}

Wielokat<KWADRAT> &Prostopadloscian::operator[](int index) {
    if (index > SCIANY || index < 0) throw std::invalid_argument("Nieprawidlowy index!");
    return sciany[index];
}

void Prostopadloscian::obrot(MacierzObrotu<STANDARD> obrotu) {
    for (int i = 0; i < SCIANY; ++i) {
        sciany[i].obrot(obrotu);
    }
}


std::ostream & operator<<(std::ostream & ost, const Prostopadloscian &pro) {
        //TODO ZROBIC WYSWIETLANIE PROSTOPADLOSCIANU
    return ost;
}
