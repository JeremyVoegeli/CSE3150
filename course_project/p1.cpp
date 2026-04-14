#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using std::cout, std::endl, std::string, std::stringstream;

int main(){
    std::ifstream file("20260301.as-rel2.txt");

    if(!file.is_open()){
        std::cerr << "Error: Couldn't open file." << endl;
        return 1;
    }

    string line;
    while (std::getline(file, line)){
        if(line[0] == '#')
            continue;

        stringstream ss(line);
        string AS1, AS2, relationship;

        std::getline(ss, AS1, '|');
        std::getline(ss, AS2, '|');
        std::getline(ss, relationship, '|');

        cout << AS1 << " - " << AS2 << " - " << relationship << endl;
    }
    return 0;
}
