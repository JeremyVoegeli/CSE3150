#pragma once
#include "abstract_decimal.h"
#include <iostream>

class Fraction : public Decimal{
private:
    int* numer_;
    int* denom_;
public:
    Fraction(); //default constructor
    Fraction(int n, int d); //custom constructor

    Fraction(const Fraction& f); //copy constructor
    Fraction(Fraction&& f); //move constructor

    Fraction& operator=(const Fraction& f); //assignment operator (lvalue)
    Fraction& operator=(Fraction&& f); //assignment operator (rvalue)

    ~Fraction(); //destructor

    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

    double convertToDecimal() override;
};
