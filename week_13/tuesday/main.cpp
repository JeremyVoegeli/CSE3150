#include "point.hpp"
#include "rectangle.hpp"
#include <iostream>
using std::cout, std::endl;

int main(){
    Rectangle* p = new Rectangle(10, 20, 100, 100);
    cout << "Before: " << *p << endl;
    delete p;
    return 0;
}
