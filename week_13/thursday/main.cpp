#include "grad.cpp"
#include <iostream>
using std::cout, std::endl;

int main(){
    UGrad s1("bob", 61);
    Grad s2("Poop name", 81);
    UGrad& gr = s2;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << gr << endl;
    return 0;
}
