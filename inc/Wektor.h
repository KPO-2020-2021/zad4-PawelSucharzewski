#pragma once 

#include <array>
#include <cmath>
#include <iostream>

const double PRECYZJA = 0.0001;
const int STANDARD = 3;

template <int ROZMIAR = STANDARD>
class Wektor {
private:
    std::array<double, ROZMIAR> liczby;
public:
    Wektor() { liczby.fill(0); }

    Wektor(const std::array<double, ROZMIAR> & argumenty) : liczby(argumenty) {}

    Wektor<ROZMIAR> operator+ (Wektor<ROZMIAR> & argument);
    Wektor<ROZMIAR> operator+= (Wektor<ROZMIAR> & argument);
    Wektor<ROZMIAR> operator- (Wektor<ROZMIAR> & argument);
    Wektor<ROZMIAR> operator-= (Wektor<ROZMIAR> & argument);
    bool operator== (Wektor<ROZMIAR> & argument);
    Wektor<ROZMIAR> operator* (double  & argument);

    const double & operator[](int index) const;
    double & operator[](int index);
};

template<int ROZMIAR>
const double &Wektor<ROZMIAR>::operator[](int index) const {
    return liczby[index];
}

template<int ROZMIAR>
double &Wektor<ROZMIAR>::operator[](int index) {
    return liczby[index];
}

template<int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator+(Wektor<ROZMIAR> &argument) {
    Wektor<ROZMIAR> wynik;
    for (int i = 0; i < ROZMIAR; ++i){
        wynik[i] = liczby[i] + argument[i];
    }
    return wynik;
}

template<int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator-(Wektor<ROZMIAR> &argument) {
    Wektor<ROZMIAR> wynik;
    for (int i = 0; i < ROZMIAR; ++i){
        wynik[i] = liczby[i] - argument[i];
    }
    return wynik;
}

template<int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator+=(Wektor<ROZMIAR> &argument) {
    for (int i = 0; i < ROZMIAR; ++i){
        liczby[i] = liczby[i] + argument[i];
    }
    return liczby;
}

template<int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator*(double &argument) {
    Wektor<ROZMIAR> wynik;
    for (int i = 0; i < ROZMIAR; ++i){
        wynik[i] = liczby[i] * argument;
    }
    return wynik;
}

template<int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator-=(Wektor<ROZMIAR> &argument) {
    for (int i = 0; i < ROZMIAR; ++i){
        liczby[i] = liczby[i] - argument[i];
    }
    return liczby;
}

template<int ROZMIAR>
bool Wektor<ROZMIAR>::operator==(Wektor<ROZMIAR> &argument) {
    for (int i = 0; i < ROZMIAR; i++) {
        if (std::abs(liczby[i] - argument[i]) >= PRECYZJA) return false;
    }
    return true;
}


template <int ROZMIAR>
std::ostream & operator<<(std::ostream & ost, const Wektor<ROZMIAR> &Vec) {

    for(int i = 0; i < ROZMIAR; ++i){
        ost << Vec[i] << " ";
    }
    return ost;
}

template <int ROZMIAR>
std::istream & operator>>(std::istream & ist, Wektor<ROZMIAR> &Vec) {
    int wart;
    for(int i = 0; i < ROZMIAR; ++i){
        std::cout << "[" << i + 1 << "]: ";
        ist >> wart;
        Vec[i] = wart;
    }
    return ist;
}

template <int ROZMIAR>
double dystansMiedzyDwomaWektorami(const Wektor<ROZMIAR> &v, const Wektor<ROZMIAR> &w) {
    double zmienna = 0;
    for (int i = 0; i < ROZMIAR; ++i) {
        zmienna += pow(abs(v[i] - w[i]), 2);
    }
    return sqrt(zmienna);
}
