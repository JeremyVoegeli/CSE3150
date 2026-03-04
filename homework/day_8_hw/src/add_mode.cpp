#include <iostream>
#include "add_mode.h"
#include <string>
#include <cctype>
using std::cout, std::endl, std::string;

namespace add_mode{
    int add(int a, int b){
        return a + b;
    }

    double add(double a, double b){
        return a + b;
    }

    string add (string a, string b){
        return a + b;
    }

    void run(int argc, char* argv[]){
        if (argc < 4){
            cout << "Not enough arguments." << endl;
            return;
        }

        string input1 = argv[2];
        string input2 = argv[3];

        if (input1.find('.') != std::string::npos || input2.find('.') != std::string::npos){
            cout << "Result " << std::to_string(add(std::stod(input1), std::stod(input2))) << endl;
            return;
        }

        bool only_digits1 = true;
        bool only_digits2 = true;

        for (char c : input1){
            if (!std::isdigit(c)){only_digits1 = false;}
        }
        for (char c : input2){
            if (!std::isdigit(c)){only_digits2 = false;}
        }

        if (only_digits1 && only_digits2){
            cout << "Result " << std::to_string(add(std::stoi(input1), std::stoi(input2))) << endl;;
            return;
        } else {
            cout << "Result " << add(input1, input2) << endl;
            return;
        }
    }
}
