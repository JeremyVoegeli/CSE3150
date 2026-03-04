#include <iostream>
#include "integer_utils.h"
#include "string_utils.h"
#include "grade_utils.h"
#include "while_count_utils.h"
#include "do_while_count_utils.h"
using std::cin, std::cout, std::endl, integer_utils::runIntegerOption, string_utils::runStringOption,
    grade_utils::calculateGrade, while_count_utils::runWhileCount,
    do_while_count_utils::runDoWhileCount;

int print_menu(){
    cout << "1. Integer operations" << endl;
    cout << "2. Character arrays and C-style strings" << endl;
    cout << "3. Grade evaulation" << endl;
    cout << "4. While-loop counting" << endl;
    cout << "5. Do-while and range-based for counting" << endl;
    cout << "6. Quit" << endl;
    return 0;
}

int main() {
    int option = 0;

    while (option != 6){
        print_menu();
        cout << "Enter menu option: ";
        cin >> option;

        int result;
        switch (option){
            case 1:
                runIntegerOption();
                break;
            case 2:
                result = runStringOption();
                if (result == 1){return 1;}
                break;
            case 3:
                result = calculateGrade();
                if (result < 0){return 1;}
                break;
            case 4:
                runWhileCount();
                break;
            case 5:
                runDoWhileCount();
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
        }
    }
    return 0;
}
