#include <iostream>
#include "integer_utils.h"
using std::cin, std::cout, std::endl;

namespace integer_utils{
    int runIntegerOption(){
        double num1;
        double num2;

        cout << "Enter first integer: ";
        cin >> num1;
        cout << "Enter second integer: ";
        cin >> num2;

        if (num2 == 0){
            cout << "Error: division by zero" << endl;
            return 0;
        }
        double quotient = num1 / num2;
        cout << "Result: " << quotient << endl;

        //This is a single line comment

        cout << "After post-increment: " << num1++ << endl;
        cout << "After pre-increment: " << ++num1 << endl;
        return 0;
    }
}
