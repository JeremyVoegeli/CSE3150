#include "fraction.h"
#include <iostream>
#include <stdexcept>

//default constructor
Fraction::Fraction() : numer_(new int(1)), denom_(new int(1)) {
    std::cout << "I am in the default constructor" << std::endl;
}

//custom constructor
Fraction::Fraction(int n, int d){
    std::cout << "I am in the custom constructor" << std::endl;
    if (d == 0) {throw std::runtime_error("Can't divide by zero!");}
    numer_ = new int(n);
    denom_ = new int(d);
}

//copy constructor
Fraction::Fraction(const Fraction& f){
    std::cout << "I am in the copy constructor" << std::endl;
    if (f.numer_ == nullptr || f.denom_ == nullptr){
        throw std::runtime_error("can't dereference null pointers");
    }

    numer_ = new int(*f.numer_);
    denom_ = new int(*f.denom_);
}

//move constructor
Fraction::Fraction(Fraction&& f){
    std::cout << "I am in the move constructor" << std::endl;
    numer_ = f.numer_;
    denom_ = f.denom_;

    f.numer_ = nullptr;
    f.denom_ = nullptr;
}

//assignment operator (lvalue)
Fraction& Fraction::operator=(const Fraction& f){
    std::cout << "I am in the assignment operator (lvalue)" << std::endl;
    if (f.numer_ == nullptr || f.denom_ == nullptr){
        throw std::runtime_error("can't dereference null pointers");
    }
    delete numer_;
    delete denom_;

    numer_ = new int(*f.numer_);
    denom_ = new int(*f.denom_);
    return *this;
}
//assignment operator (rvalue)
Fraction& Fraction::operator=(Fraction&& f){
    std::cout << "I am in the assignment operator (rvalue)" << std::endl;

    delete numer_;
    delete denom_;

    numer_ = f.numer_;
    denom_ = f.denom_;
    f.numer_ = nullptr;
    f.denom_ = nullptr;
    return *this;
}

//destructor
Fraction::~Fraction(){
    std::cout << "I am in the destructor" << std::endl;
    delete numer_;
    delete denom_;
}

//plus operator
Fraction operator+(const Fraction& f1, const Fraction& f2){
    std::cout << "I am in the plus operator" << std::endl;
    if (f1.numer_ == nullptr || f1.denom_ == nullptr){
        throw std::runtime_error("can't dereference null pointers");
    }
    if (f2.numer_ == nullptr || f2.denom_ == nullptr){
        throw std::runtime_error("can't dereference null pointers");
    }
    int n = *f1.numer_ * *f2.denom_ + *f1.denom_ * *f2.numer_;
    int d = *f1.denom_ * *f2.denom_;
    return Fraction(n, d);
}

//multiplication operator
Fraction operator*(const Fraction& f1, const Fraction& f2){
    std::cout << "I am in the multiplication operator" << std::endl;
    if (f1.numer_ == nullptr || f1.denom_ == nullptr){
        throw std::runtime_error("can't dereference null pointers");
    }
    if (f2.numer_ == nullptr || f2.denom_ == nullptr){
        throw std::runtime_error("can't dereference null pointers");
    }
    int n = *f1.numer_ * *f2.numer_;
    int d = * f1.denom_ * *f2.denom_;
    return Fraction(n, d);
}

//output stream operator
std::ostream& operator<<(std::ostream& os, const Fraction& f){
    std::cout << "I am in the << operator" << std::endl;
    if (f.numer_ == nullptr || f.denom_ == nullptr){
        throw std::runtime_error("can't dereference null pointers");
    }
    os << *f.numer_ << "/" << *f.denom_;
    return os;
}

double Fraction::convertToDecimal(){
    std::cout << "I am in the convertToDecimal() function" << std::endl;
    double dub_n = *numer_;
    double dub_d = *denom_;
    return dub_n / dub_d;
}
