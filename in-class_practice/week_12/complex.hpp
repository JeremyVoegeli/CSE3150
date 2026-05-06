#pragma once
#include <iostream>

class Complex{
private:
    double real_;
    double imag_;

    Complex add(const Complex& c2) const
public:
    Complex(): real_(0), imag_(0) {}
    Complex(double a, double b): real_(a), imag_(b) {}

    Complex(const Complex& c): real_(c.real_), imag_(c.imag_) {}

    Complex& operator=(const Complex& c){
        real_ = c.real_;
        imag_ = c.imag_;
        return *this;
    }

    friend Complex operator+(const Complex& a, const Complex& b){
        return a.add(b);
    }

    void print(std::ostream& os){

    }
};
