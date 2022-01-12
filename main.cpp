#include <iostream>

#include "library.h"

using namespace std;

int main()
{
    int stopien1, stopien2;
    cout << "Podaj stopien pierwszego wielomianu:\n";
    cin >> stopien1;
    double *array1 = new double[stopien1 + 1];
    for (int i = stopien1; i >= 0; i--)
    {
        cout << "Podaj wartosc x^" << i << ":\n";
        cin >> array1[i];
    }
    //tworzymy pierwszy obiekt, wywolujemy kontruktor inicjalizujacy wartosci
    Polynomial poly1(array1, stopien1 + 1);
    cout << "Wielomian1: ";
    poly1.displayPolynomial();

    cout << "Podaj stopien drugiego wielomianu:\n";
    cin >> stopien2;
    double *array2 = new double[stopien2 + 1];
    for (int i = stopien2; i >= 0; i--)
    {
        cout << "Podaj wartosc x^" << i << ":\n";
        cin >> array2[i];
    }
    Polynomial poly2(array2, stopien2 + 1);
    cout << "Wielomian2: ";
    poly2.displayPolynomial();

    cout << "wielomian1 + wielomian2: ";
    poly1.Add(poly2).displayPolynomial();

    cout << "wielomian1 - wielomian2: ";
    poly1.Substract(poly2).displayPolynomial();

    cout << "wielomian1 * wielomian2: ";
    poly1.Multiply(poly2).displayPolynomial();

    int x1, x2;
    cout << "Podaj punkt x w ktorym obliczymy wartosc wielomianu1: " << endl;
    cin >> x1;
    cout << "Wynik: " << poly1.Horner(x1) << endl;
    cout << "Podaj punkt x w ktorym obliczymy wartosc wielomianu2: " << endl;
    cin >> x2;
    cout << "Wynik: " << poly2.Horner(x2) << endl;

    return 0;
}