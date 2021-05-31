#pragma once

#include "Wektor.h"

template<int ROZMIAR>
class MacierzObrotu {
private:
    std::array<Wektor<ROZMIAR>, ROZMIAR> tablica;
public:
    MacierzObrotu(double diag = 1);

    MacierzObrotu(double kat, char os_obrotu);

    MacierzObrotu<ROZMIAR> operator*(const MacierzObrotu<ROZMIAR> &macierz);

    MacierzObrotu<ROZMIAR> operator+(const MacierzObrotu<ROZMIAR> &macierz);

    MacierzObrotu<ROZMIAR> operator+=(const MacierzObrotu<ROZMIAR> &macierz);

    MacierzObrotu<ROZMIAR> operator-(const MacierzObrotu<ROZMIAR> &macierz);

    MacierzObrotu<ROZMIAR> operator*(const int &liczb);

    Wektor<ROZMIAR> operator*(const Wektor<ROZMIAR> &wektor) const;

    bool operator==(const MacierzObrotu<ROZMIAR> &macierz);

    const Wektor<ROZMIAR> &operator[](int index) const;

    Wektor<ROZMIAR> &operator[](int index);
};

template<int ROZMIAR>
MacierzObrotu<ROZMIAR>::MacierzObrotu(double diag) {
    for (int i = 0; i < ROZMIAR; ++i) {
        tablica[i][i] = diag;
    }
}

template<int ROZMIAR>
MacierzObrotu<ROZMIAR>::MacierzObrotu(double kat, char os_obrotu) {
    kat *= (M_PI / 180);

    switch (os_obrotu) {
        case 'x':
            tablica[0] = Wektor<3>({1, 0, 0});
            tablica[1] = Wektor<3>({0, std::cos(kat), -std::sin(kat)});
            tablica[2] = Wektor<3>({0, std::sin(kat), std::cos(kat)});
            break;
        case 'y':
            tablica[0] = Wektor<3>({std::cos(kat), 0, std::sin(kat)});
            tablica[1] = Wektor<3>({0, 1, 0});
            tablica[2] = Wektor<3>({-std::sin(kat), 0, std::cos(kat)});
            break;
        case 'z':
            tablica[0] = Wektor<3>({std::cos(kat), -std::sin(kat), 0});
            tablica[1] = Wektor<3>({std::sin(kat), std::cos(kat), 0});
            tablica[2] = Wektor<3>({0, 0, 1});
            break;
        default:
            throw std::invalid_argument("Nie ma takiej osi!");
    }
}

template<int ROZMIAR>
MacierzObrotu<ROZMIAR> MacierzObrotu<ROZMIAR>::operator*(const MacierzObrotu<ROZMIAR> &macierz) {
    MacierzObrotu<ROZMIAR> wynik(0);
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            for (int k = 0; k < ROZMIAR; ++k) {
                wynik[i][j] += tablica[i][k] * macierz[k][j];
            }
        }
    }
    return wynik;
}

template<int ROZMIAR>
const Wektor<ROZMIAR> &MacierzObrotu<ROZMIAR>::operator[](int index) const {
    return tablica[index];
}

template<int ROZMIAR>
Wektor<ROZMIAR> &MacierzObrotu<ROZMIAR>::operator[](int index) {
    return tablica[index];
}

template<int ROZMIAR>
MacierzObrotu<ROZMIAR> MacierzObrotu<ROZMIAR>::operator+(const MacierzObrotu<ROZMIAR> &macierz) {
    MacierzObrotu<ROZMIAR> wynik(0);
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            wynik[i][j] = macierz[i][j] + tablica[i][j];
        }
    }
    return wynik;
}

template<int ROZMIAR>
MacierzObrotu<ROZMIAR> MacierzObrotu<ROZMIAR>::operator-(const MacierzObrotu<ROZMIAR> &macierz) {
    MacierzObrotu<ROZMIAR> wynik(0);
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            wynik[i][j] = tablica[i][j] - macierz[i][j];
        }
    }
    return wynik;
}

template<int ROZMIAR>
MacierzObrotu<ROZMIAR> MacierzObrotu<ROZMIAR>::operator*(const int &liczb) {
    MacierzObrotu<ROZMIAR> wynik(0);
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            wynik[i][j] = tablica[i][j] * liczb;
        }
    }
    return wynik;
}

template<int ROZMIAR>
bool MacierzObrotu<ROZMIAR>::operator==(const MacierzObrotu<ROZMIAR> &macierz) {
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            if (std::abs(tablica[i][j] - macierz[i][j]) >= PRECYZJA) return false;
        }
    }
    return true;
}

template<int ROZMIAR>
MacierzObrotu<ROZMIAR> MacierzObrotu<ROZMIAR>::operator+=(const MacierzObrotu<ROZMIAR> &macierz) {
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            tablica[i][j] = tablica[i][j] + macierz[i][j];
        }
    }
    return *this;
}


template<int ROZMIAR>
Wektor<ROZMIAR> MacierzObrotu<ROZMIAR>::operator*(const Wektor<ROZMIAR> &wektor) const {
    Wektor<ROZMIAR> wynik;
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            wynik[i] += wektor[j] * tablica[i][j];
        }
    }
    return wynik;
}

template<int ROZMIAR>
std::ostream &operator<<(std::ostream &ost, const MacierzObrotu<ROZMIAR> &macierz) {
    for (int i = 0; i < ROZMIAR; ++i) {
        ost << "[ " << macierz[i] << "] \n";
    }
    return ost;
}

