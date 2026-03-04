#include <iostream>
#include "while_count_utils.h"
using std::cin, std::cout, std::endl;

namespace while_count_utils{
    int runWhileCount(){
        int num;
        cout << "Enter a number to count to: ";
        cin >> num;
        cout << endl;

        while (num > 10){
            cout << "I'm programmed to only count up to 10!" << endl;
            cout << "Enter a number to count to: ";
            cin >> num;
        }

        int i = 1;
        while (i <= num){
            if (i != 5){cout << i << endl;}
            i++;
        }

        return 0;
    }
}
