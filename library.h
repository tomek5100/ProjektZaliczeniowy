#ifndef LIBRARY_H
#define LIBRARY_H

class Polynomial
{
private:
    double *tab;
    int stopien;

public:
    Polynomial(int stopien);
    ~Polynomial();
};

#endif