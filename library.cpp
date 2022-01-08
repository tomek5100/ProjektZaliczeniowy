#include <iostream>
#include "library.h"

using namespace std;

//konstruktor domyslny, tworzy pusty wielomian
Polynomial::Polynomial()
{
    arr_size = 1;
    coefficient_arr = new double[1];
    coefficient_arr[0] = 0;
}

//tworzy wielomian zainicjalizowany na zero
Polynomial::Polynomial(int degree)
{
    arr_size = degree + 1;
    coefficient_arr = new double[arr_size];
    //inicjalizuje zerami
    fill_n(coefficient_arr, arr_size, 0);
}

//tworzy wielomian i inicjalizuje wartosci
Polynomial::Polynomial(double *arr, int coefficient)
{
    arr_size = coefficient;
    coefficient_arr = new double[arr_size];
    //inicjalizuje tablice wartosciami przekazanymi poprzez
    //argumnent - tablice arr
    for (int i = 0; i < coefficient; i++)
    {
        coefficient_arr[i] = arr[i];
    }
}

//konstruktor kopiujacy
Polynomial::Polynomial(Polynomial &other)
{
    arr_size = other.arr_size;
    coefficient_arr = new double[arr_size];
    //kopiuje wartosci wspolczynnikow
    for (int i = 0; i < arr_size; i++)
    {
        coefficient_arr[i] = other.coefficient_arr[i];
    }
}

//destruktor
Polynomial::~Polynomial()
{
    delete[] coefficient_arr;
    arr_size = 0;
    coefficient_arr = nullptr;
}

//dodaje jeden wielomian do drugiego
Polynomial Polynomial::Add(Polynomial &other)
{
    //sprawdzamy ktory wielomian ma wiekszy stopien
    int resultSize = (arr_size >= other.arr_size) ? arr_size : other.arr_size;
    //tworzymy nowy obiekt, stopien o 1 mniejszy od arr_size
    Polynomial result(resultSize - 1);

    if (arr_size >= other.arr_size)
    {
        for (int i = 0; i < other.arr_size; i++)
        {
            //jesli other.arr ma mniejszy stopien to odejmuje tylko wspolczynniki do rozmiaru other.arrsize
            result.coefficient_arr[i] = coefficient_arr[i] - other.coefficient_arr[i];
        }
        for (int i = 0; i < other.arr_size; i++)
        {
            //pozosotale wspolczynniki przepisuje
            result.coefficient_arr[i] = coefficient_arr[i];
        }
    }
    else
    {
        for (int i = 0; i < arr_size; i++)
        {
            result.coefficient_arr[i] = coefficient_arr[i] - other.coefficient_arr[i];
        }
        for (int i = 0; i < arr_size; i++)
        {
            result.coefficient_arr[i] = coefficient_arr[i];
        }
    }
}

//odejmuje wielomiany
Polynomial Polynomial::Substract(Polynomial &other)
{
}

//mnozenie wielomanow
Polynomial Polynomial::Multiply(Polynomial &other)
{
}

//zwraca stopien wielomanu
int Polynomial::degree()
{
}

//jeszcze horner

//wyswietla wielomian
void Polynomial::displayPoly()
{
}