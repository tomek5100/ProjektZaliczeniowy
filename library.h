#ifndef LIBRARY_H
#define LIBRARY_H

class Polynomial
{
private:
    double *coefficient_arr;
    int arr_size; //jest o jeden wieksza od stopnia wielomianu
    //rozmiar tablicy musi byc wiekszy o 1 od stopnia wielomianu
    //motywacja
    //int stopien = 2
    //x^2 + x + c --> trzy wspolczynniki

public:
    //tworzy pusty wielomian
    Polynomial();

    //tworzy wielomian zainicjalizowany na zero
    Polynomial(int degree);

    //tworzy wielomian i inicjalizuje wartosci
    Polynomial(double *arr, int coefficient);

    //konstruktor kopiujacy
    Polynomial(Polynomial &other);

    //destruktor
    ~Polynomial();

    //dodaje jeden wielomian do drugiego
    Polynomial Add(Polynomial &other);

    //odejmuje wielomiany
    Polynomial Substract(Polynomial &other);

    //mnozenie wielomanow
    Polynomial Multiply(Polynomial &other);

    //zwraca stopien wielomanu
    int degree();

    //jeszcze horner

    //wyswietla wielomian
    void displayPoly();
};

#endif