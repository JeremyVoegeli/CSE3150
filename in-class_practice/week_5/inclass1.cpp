#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using std::cout, std::cerr, std::endl, std::string;

int main(){
    std::ifstream file("data.txt");

    if (!file.is_open()){
        cerr << "Failed to open file" << endl;
        return 1;
    }

    string line;
    int n = 1;
    while (std::getline(file, line)){
        int words = 0;
        bool in_word = false;
        for (char c : line){
            if (!std::isspace(c)){
                if(!in_word){
                    words++;
                    in_word = true;
                }
            } else {
                in_word = false;
            }
        }
        cout << "Line " << n <<": " <<  words << " words" <<  endl;
        n++;
    }
    return 0;
}
