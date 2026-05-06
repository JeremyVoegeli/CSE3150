#include "math_utils.hpp"
#include <iostream>

using std::cout, std::endl, MathUtils::add, MathUtils::subtract, MathUtils::multiply;

int main() {
    int x = 4;
    int y = 7;

    cout << "Sum: " << add(x, y) << endl;
    cout << "Difference: " << subtract(x, y) << endl;
    cout << "Product: " << multiply(x, y) << endl;
    return 0;
}
