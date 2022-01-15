#ifndef LIBRARY_H
#define LIBRARY_H

class Polynomial
{
private:
    double *coefficient_arr;
    int arr_size; //rozmiar tablicy jest o jeden wiekszy od stopnia wielomianu
    //przyklad:
    //int stopien = 2
    //x^2 + x + c --> trzy wspolczynniki

public:
    //konstruktor - tworzy wielomian zainicjalizowany na zero
    Polynomial(int degree);

    //konstruktor - tworzy wielomian i inicjalizuje wartosci
    Polynomial(double *arr, int coefficient);

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

    //obliczanie wartosci wielomianu metoda Hornera
    double Horner(double value);

    //wyswietla wielomian
    void displayPolynomial();
};

#endif