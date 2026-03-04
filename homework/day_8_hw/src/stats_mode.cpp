#include "stats_mode.h"
#include <iostream>
#include <string>
#include <cctype>

using std::cout, std::endl, std::string;

namespace stats_mode{
    void run(int argc, char* argv[]){
        if (argc < 3){
            cout << "Not enough arguments." << endl;
            return;
        }

        string input = argv[2];
        size_t length = input.size();
        cout << "Length " << length << endl;

        int unique_count = 0;
        string unique_chars = "";
        bool isalphanum = true;
        string reversed = "";
        string without_spaces = "";
        string lower = "";
        string reversed_lower = "";

        for (char c : input){
            if (unique_chars.find(c) == std::string::npos){
                unique_chars += c;
                unique_count++;
            }

            if (!std::isalnum(c)){
                isalphanum = false;
            }

            if(c != ' '){
                without_spaces += c;
                lower += std::tolower(c);
                char l = std::tolower(c);
                reversed_lower = l + reversed_lower;
            }

            reversed = c + reversed;
        }

        cout << "Unique " << unique_count << endl;

        if (isalphanum){cout << "Alphanumeric Yes" << endl;}
        else {cout << "Alphanumeric No" << endl;}

        cout << "Reversed " << reversed << endl;
        cout << "Without spaces " << without_spaces << endl;

        if (lower == reversed_lower){
            cout << "Palindrome Yes" << endl;
        } else {
            cout << "Palindrome No" << endl;
        }
    }
}
