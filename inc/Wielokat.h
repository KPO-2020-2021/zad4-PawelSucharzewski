#pragma once

#include "MacierzObrotu.h"
#include "Wykres.h"

const std::string KOLOR = "#000000";
const int KWADRAT = 4;

template<int KATY = KWADRAT>
class Wielokat {
private:
    double promien;
    std::array<Wektor<STANDARD>, KATY> punkty;
    std::string id;
    std::string kolor;
public:
    Wielokat(double promien = 100);

    Wielokat(double promien, char orientacja);

    Wielokat(Wektor<STANDARD> v, Wektor<STANDARD> w, Wektor<STANDARD> wektorTranslacji = Wektor<STANDARD>());


    void translacja(Wektor<STANDARD> wektorTranslacji);

    void obrot(double kat, char os_obrotu);

    void obrot(MacierzObrotu<STANDARD> obrotu);

    void rysuj();

    const Wektor<STANDARD> &operator[](int index) const;

    Wektor<STANDARD> &operator[](int index);
};

template<int KATY>
Wielokat<KATY>::Wielokat(const double promien) {
    kolor = KOLOR;
    punkty[0][1] = promien;
    double kat = 360 / KATY;
    MacierzObrotu<3> mac(kat, 'x');
    for (int i = 1; i < KATY; ++i) {
        punkty[i] = mac * punkty[i - 1];
    }
}

template<int KATY>
Wielokat<KATY>::Wielokat(double promien, char orientacja) {
    kolor = KOLOR;
    punkty[0][0] = promien;
    double kat = 360 / KATY;
    MacierzObrotu<3> mac(kat, 'y');
    for (int i = 1; i < KATY; ++i) {
        punkty[i] = mac * punkty[i - 1];
    }
}

template<int KATY>
Wielokat<KATY>::Wielokat(Wektor<STANDARD> v, Wektor<STANDARD> w, Wektor<STANDARD> wektorTranslacji) {
    kolor = KOLOR;
    punkty[0] = Wektor<STANDARD>();
    punkty[1] = v;
    punkty[2] = v + w;
    punkty[3] = w;
    translacja(wektorTranslacji);
}


template<int KATY>
void Wielokat<KATY>::obrot(double kat, char os_obrotu) {
    MacierzObrotu<3> mac(kat, os_obrotu);
    for (int i = 0; i < KATY; ++i) {
        punkty[i] = mac * punkty[i];
    }
}

template<int KATY>
void Wielokat<KATY>::translacja(Wektor<STANDARD> wektorTranslacji) {
    for (int i = 0; i < KATY; ++i) {
        punkty[i] = punkty[i] + wektorTranslacji;
    }
}

template<int KATY>
const Wektor<STANDARD> &Wielokat<KATY>::operator[](int index) const {
    if (index > KATY || index < 0) throw std::invalid_argument("Nieprawidlowy index!");
    return punkty[index];
}

template<int KATY>
Wektor<STANDARD> &Wielokat<KATY>::operator[](int index) {
    if (index > KATY || index < 0) throw std::invalid_argument("Nieprawidlowy index!");
    return punkty[index];
}

template<int KATY>
void Wielokat<KATY>::rysuj() {
    if (id.empty()) {
        id = "W#" + std::to_string(listaObiektow.size() + 1);
    }
    std::stringstream tmp, command;
    tmp << "from " << punkty[0][0] << "," << punkty[0][2] << "," << punkty[0][1] << " to ";
    for (int i = 1; i < KATY; ++i) {
        tmp << punkty[i][0] << "," << punkty[i][2] << "," << punkty[i][1] << " to ";
    }
    tmp << punkty[0][0] << "," << punkty[0][2] << "," << punkty[0][1];

    if (listaObiektow.find(id) == listaObiektow.end()) {
        listaObiektow[id] = listaObiektow.size() + 1;
    }

    command << "set object " << listaObiektow[id] << " polygon " << tmp.str() <<
            " fillstyle transparent solid fillcolor rgb \"" << kolor << "\"";

    wykres.sendcommand(command.str());
}

template<int KATY>
void Wielokat<KATY>::obrot(MacierzObrotu<STANDARD> obrotu) {
    for (int i = 0; i < KATY; ++i) {
        punkty[i] = obrotu * punkty[i];
    }
}

