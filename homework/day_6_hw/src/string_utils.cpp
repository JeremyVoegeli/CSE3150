#include <iostream>
#include <string>
#include "string_utils.h"
using std::cout, std::endl, std::cin, std::getline;

namespace string_utils{
    int runStringOption(){
        int len;
        cout << "Enter string length: ";
        cin >> len;

        if (len >= 20){
            cout << "Error: string length must be less than 20." << endl;
            return 1;
        }

        cin.ignore();

        std::string input;
        cout << "Enter string: ";
        getline(cin, input);

        char arr[20] = {};

        int i;
        for (i = 0; i < len; i++){
            arr[i] = input[i];
        }
        arr[i] = '\0';

        cout << "C-style string: " << arr << endl;
        return 0;
    }
}
