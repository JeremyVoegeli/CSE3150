#include <iostream>
#include <fstream>
using std::cout, std::endl, std::string, std::cin;

int main(){
    std::ifstream file("data.txt");
    if (!file){
        std::cerr << "Failed to open file" << endl;
    }
    file.close();
    return 0;
}
