#include "Scena.h"

void wyswietlMenuProgramu();

int main() {
    Scena scena;
    char opcja = ' ';

    wyswietlMenuProgramu();
    do {
        std::cout << "Wpisz opcje: ";
        std::cin >> opcja;
        switch (opcja) {
            case 'O':
            case 'o':
                scena.zrobRotacje();
                scena.rysuj();
                break;
            case 'T':
            case 't':
                scena.ustawMacierzPoprzedniejRotacji();
                scena.rysuj();
                break;
            case 'R':
            case 'r':
                scena.wyswietlMacierzRotacji();
                break;
            case 'P':
            case 'p':
                scena.zrobTranslacje();
                scena.rysuj();
                break;
            case 'W':
            case 'w':
                scena.pokazWektory();
                break;
            case 'M':
            case 'm':
                wyswietlMenuProgramu();
                break;
            case 'K':
            case 'k':
                break;
            default:
                std::cout << "Nie ma takiej opcji !\n";
                break;
        }
    } while (opcja != 'k');

    return 0;
}

void wyswietlMenuProgramu(){
    std::cout << std::endl
         <<"O - Obróć bryły o zadany kąt         " << std::endl
         <<"T - Powtórzenie poprzedniego obrotu  " << std::endl
         <<"R - wyświetlenie macierzy rotacji    " << std::endl
         <<"P - Przesuń o zadany wektor          " << std::endl
         <<"W - Wyświetl długości boków          " << std::endl
         <<"M - Wyświetl menu                    " << std::endl
         <<"K - Koniec działania programu        " << std::endl
         <<"Twój wybór: ";
}
