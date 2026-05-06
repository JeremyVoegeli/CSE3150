#include <iostream>
#include <string>
using std::cout, std::cin, std::endl, std::string;

int main(){
    string s = "Hello";
    for (const char& c : s){ //const to not accidentally change s, char& to not copy string
        cout << c << endl;
    }
    return 0;
}
