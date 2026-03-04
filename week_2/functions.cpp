#include <iostream>

double divide(double x, double y) {return x / y;}

int main() {
    double numerator = 5;
    double denominator = 2;
    std::cout << divide(numerator, denominator) << std::endl;
    return 0;
}
