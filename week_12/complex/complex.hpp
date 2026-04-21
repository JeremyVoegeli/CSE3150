#pragma once
#include <iostream>

class Complex{
private:
    double real_;
    double imag_;

public:
    Complex(): real_(0), imag_(0) {}
    Complex(double a, double b): real_(a), imag_(b) {}

    Complex(const Complex& c): real_(c.real_), imag_(c.imag_) {}

    Complex add(const Complex& c2){
        const double r = real_ + c2.real_;
        const double i = imag_ + c2.imag_;
        return Complex(r, i);
    }

    void print(std::ostream& os);
};
