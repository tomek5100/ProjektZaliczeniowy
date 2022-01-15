#include <iostream>
#include "library.h"

using namespace std;

//konstruktor domyslny, tworzy pusty wielomian
// Polynomial::Polynomial()
// {
//     arr_size = 1;
//     coefficient_arr = new double[1];
//     coefficient_arr[0] = 0;
// }

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
            result.coefficient_arr[i] = coefficient_arr[i] + other.coefficient_arr[i];
        }
        for (int i = other.arr_size; i < arr_size; i++)
        {
            //pozosotale wspolczynniki przepisuje
            result.coefficient_arr[i] = coefficient_arr[i];
        }
    }
    else
    {
        for (int i = 0; i < arr_size; i++)
        {
            result.coefficient_arr[i] = coefficient_arr[i] + other.coefficient_arr[i];
        }
        for (int i = arr_size; i < other.arr_size; i++)
        {
            result.coefficient_arr[i] = other.coefficient_arr[i];
        }
    }
    return result;
}

//odejmuje wielomiany
Polynomial Polynomial::Substract(Polynomial &other)
{
    //dziala tak samo jak dodawanie, lecz zamieniamy + na - w dwoch miejscach
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
        for (int i = other.arr_size; i < arr_size; i++)
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
        for (int i = arr_size; i < other.arr_size; i++)
        {
            result.coefficient_arr[i] = -(other.coefficient_arr[i]);
        }
    }
    return result;
}

//mnozenie wielomanow
Polynomial Polynomial::Multiply(Polynomial &other)
{
    //najwyzsza potega wielomianu to suma rozmiaru dwoch tablic - 2(bo wspolczynnik x^0)
    int result_degree = arr_size + other.arr_size - 2;
    //tworzymy nowy obiekt
    Polynomial result(result_degree);

    //mnozenie polega na wymnozeniu kazdego elementu 1)wielomianu z 2)
    for (int i = 0; i < arr_size; i++) //przegladamy wszystkie elementy 1) wielomianu
    {
        for (int j = 0; j < other.arr_size; j++) //przegladamy wszyskie elementy 2) wielomianu
        {
            //[i+j] poniewaz przy mnozeniu poteg, jest to suma wspolczynnikow
            result.coefficient_arr[i + j] += (coefficient_arr[i] * other.coefficient_arr[j]);
        }
    }
    return result;
}

//zwraca stopien wielomanu
int Polynomial::degree()
{
    return arr_size - 1;
}

//obliczanie wartosci wielomianu metoda Hornera
double Polynomial::Horner(double x)
{
    double result = 0;
    if (arr_size == 1){
        result = coefficient_arr[0];
    }
    else
    {
        result = coefficient_arr[arr_size - 1];
        for (int i = arr_size - 2; i >= 0; i--)
        {
            result = result * x + coefficient_arr[i];
        }
    }
    return result;
}

//wyswietla wielomian
void Polynomial::displayPolynomial()
{
    for (int i = arr_size - 1; i > 0; i--)
    {
        cout << "(" << coefficient_arr[i] << "x^" << i << ") + ";
    }
    cout << "(" << coefficient_arr[0] << ")" << endl;
}