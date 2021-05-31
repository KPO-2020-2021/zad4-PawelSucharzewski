#ifndef ROTACJE3D_SCENA_H
#define ROTACJE3D_SCENA_H

#include "Prostopadloscian.h"

class Scena {
private:
    Prostopadloscian prostopadloscian;
    MacierzObrotu<STANDARD> macierzRotacji;
    MacierzObrotu<STANDARD> macierzRotacjiPoprzedniej;
    MacierzObrotu<STANDARD> macierzRotacjiCalkowitej;

    Wektor<STANDARD> wektorTranslacji;
    Wektor<STANDARD> wektorTranslacjiCalkowitej;

public:
    Scena();

    void wyswietlMacierzRotacji();
    void zrobTranslacje();
    void zrobRotacje();
    void pokazWektory();
    void ustawMacierzPoprzedniejRotacji();
    void rysuj();
};

#endif //ROTACJE3D_SCENA_H
