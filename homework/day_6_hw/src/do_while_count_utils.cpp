#include <iostream>
#include "do_while_count_utils.h"
using std::cout, std::endl, std::cin;

namespace do_while_count_utils{
    int runDoWhileCount(){
        int n;
        do {
            cout << "Enter a number between 1 and 5: ";
            cin >> n;
        } while (n < 1 || n > 5);

        int arr[5] = {1, 2, 3, 4, 5};

        for (int i : arr){
            cout << "Value: " << i << endl;
            if (i == n) {break;}
        }
        return 0;
    }
}
