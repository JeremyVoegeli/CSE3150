#include <iostream>
#include <string>
#include <cctype>
#include "text_mode.h"
using std::cout, std::cerr, std::endl, std::string;

namespace text_mode{
    void run(int argc, char* argv[]){
        if (argc < 3){
            cerr << "Missing arguments." << endl;
            return;
        }

        string s = argv[2];
        cout << "Original " << argv[2] << endl;

        size_t len = s.size();
        cout << "Length " << len << endl;

        int letters = 0;
        int digits = 0;
        int spaces = 0;
        int punct = 0;

        for (char c : s){
            if (std::isalpha(c)){letters++;}
            else if (std::isdigit(c)){digits++;}
            else if (std::isspace(c)){spaces++;}
            else if (std::ispunct(c)){punct++;}
        }

        cout << "Letters " << letters << endl;
        cout << "Digits " << digits << endl;
        cout << "Spaces " << spaces << endl;
        cout << "Punctuation " << punct << endl;

        string upper_copy;
        for (size_t i = 0; i < len; i++){
            upper_copy += std::toupper(s[i]);
            s[i] = std::tolower(s[i]);
        }

        cout << "Uppercase " << upper_copy << endl;
        cout << "Lowercase " << s << endl;

        cout << "containstest";
        if (s.find("test") != std::string::npos){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

        if (spaces > 0){
            string first_word = s.substr(0, s.find(' '));
            cout << "First word " << first_word << endl;
        }
    }
}
