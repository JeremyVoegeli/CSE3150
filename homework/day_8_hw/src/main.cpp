#include <iostream>
#include <string>
#include "text_mode.h"
#include "add_mode.h"
#include "stats_mode.h"
using std::cout, std::endl, std::string;

int main(int argc, char* argv[]){
    if (argc < 2){
        cout << "Usage: ./analyzer <mode> [arguments]" << endl;
        return 1;
    }

    string mode = argv[1];
    int int_mode = 0;

    if (mode == "text"){int_mode = 1;}
    else if (mode == "add"){int_mode = 2;}
    else if (mode == "stats"){int_mode = 3;}

    switch (int_mode){
        case 1:
            text_mode::run(argc, argv);
            break;
        case 2:
            add_mode::run(argc, argv);
            break;
        case 3:
            stats_mode::run(argc, argv);
            break;
        default:
            cout << "Invalid mode" << endl;
            return 1;
    }

    return 0;
}
