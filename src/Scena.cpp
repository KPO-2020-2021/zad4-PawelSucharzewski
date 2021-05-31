#include "Scena.h"

Scena::Scena() {
    prostopadloscian = Prostopadloscian(30, 50, 50, "#FF0000");
    macierzRotacji = MacierzObrotu<STANDARD>(1);
    macierzRotacjiCalkowitej = MacierzObrotu<STANDARD>(1);
    macierzRotacjiPoprzedniej = MacierzObrotu<STANDARD>(1);
    wektorTranslacji = Wektor<STANDARD>();
    wektorTranslacjiCalkowitej = Wektor<STANDARD>();
}

void Scena::wyswietlMacierzRotacji() {
    std::cout << macierzRotacjiPoprzedniej << std::endl;
}

void Scena::zrobTranslacje() {
    std::cout << "Podaj wektor translacji: \n";
    std::cin >> wektorTranslacji;
}

void Scena::zrobRotacje() {
    char os = ' ';
    double kat = 0;
    MacierzObrotu<STANDARD> tmp;
    std::cout << "Podaj os i kat ( np. x 90 ): \n";
    while (os != '.') { // nie wyswietla po obrocie i nie moge wyjsc z petli
        std::cin >> os;
        std::cin >> kat;
        if (os == 'x' || os == 'y' || os == 'z')
            macierzRotacji = MacierzObrotu<STANDARD>(kat, os) * macierzRotacji;
    }
}

void Scena::pokazWektory() {
    double x = dystansMiedzyDwomaWektorami(prostopadloscian[0][0], prostopadloscian[0][3]) / 2;
    double y = dystansMiedzyDwomaWektorami(prostopadloscian[0][0], prostopadloscian[1][0]) / 2;
    double z = dystansMiedzyDwomaWektorami(prostopadloscian[0][0], prostopadloscian[0][1]) / 2;

    std::cout << "Dlugosc: " << x << std::endl;
    std::cout << "Wysokosc: " << y << std::endl;
    std::cout << "Szerokosc: " << z << std::endl;
}

void Scena::ustawMacierzPoprzedniejRotacji() {
    macierzRotacji = macierzRotacjiPoprzedniej;
}

void Scena::rysuj() {
    wektorTranslacjiCalkowitej += wektorTranslacji;
    prostopadloscian.translacja(wektorTranslacji[0], wektorTranslacji[1], wektorTranslacji[2]);

    macierzRotacjiCalkowitej = macierzRotacjiCalkowitej * macierzRotacji;
    prostopadloscian.obrot(macierzRotacji);

    prostopadloscian.rysuj();
    wykres.rysujWykres();

    macierzRotacjiPoprzedniej = macierzRotacji;
    macierzRotacji = MacierzObrotu<STANDARD>(1);
    wektorTranslacji = Wektor<STANDARD>();
}

