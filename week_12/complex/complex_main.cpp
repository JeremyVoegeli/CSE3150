//this is main.cpp for all files using complex numbers

#include "complex.hpp"
#include <iostream>
using std::cout, std::endl;

int main(){
    Complex c1(1, 2);
    Complex c2(c1);
    Complex c3 = c1 + c2;

    cout << "c1: "; c1.print(cout); cout << endl;
    cout << "c2: "; c2.print(cout); cout << endl;
    cout << "c3: "; c3.print(cout); cout << endl;
    return 0;
}
