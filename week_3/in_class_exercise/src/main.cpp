#include "math_extras.hpp"
#include "check_utils.hpp"
#include <iostream>

using std::cout, std::endl, MathExtras::factorial, CheckUtils::is_even, CheckUtils::is_odd;

int main() {
    int a = 5;
    int b = 6;

    if (is_even(a)){cout << a << " is even" << endl;}
    else{cout << a << " is odd" << endl;}

    if (is_odd(b)){cout << b << " is odd" << endl;}
    else{cout << b<< " is even" << endl;}

    cout << "Factorial(" << a << ") = " << factorial(a) << endl;
    return 0;
}
