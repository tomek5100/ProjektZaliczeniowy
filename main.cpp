#include <iostream>

#include "library.h"

using namespace std;

int main()
{
    int wspolczynnik1, wspolczynnik2;
    cout << "Podaj wspolczynnik pierwszego wielomianu:\n";
    cin >> wspolczynnik1;
    double *array1 = new double[wspolczynnik1 + 1];
    for (int i = wspolczynnik1; i >= 0; i--)
    {
        cout << "Podaj wartosc x^" << i << ":\n";
        cin >> array1[i];
    }
    //tworzymy pierwszy obiekt, wywolujemy kontruktor inicjalizujacy wartosci
    Polynomial poly1(array1, wspolczynnik1 + 1); 
    poly1.displayPolynomial();

    cout << "Podaj wspolczynnik drugiego wielomianu:\n";
    cin >> wspolczynnik2;
    double *array2 = new double[wspolczynnik2 + 1];
    for (int i = wspolczynnik2; i >= 0; i--)
    {
        cout << "Podaj wartosc x^" << i << ":\n";
        cin >> array2[i];
    }
    Polynomial poly2(array2, wspolczynnik2 + 1); 
    poly2.displayPolynomial();

    // cout << "wielomian1 + wielomian2: ";
    // Polynomial result1;
    // result1 = poly1.Add(poly2);
    // result1.displayPolynomial();


    return 0;
}