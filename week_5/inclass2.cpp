#include <iostream>
#include <fstream>
#include <string>
using std::cin, std::cout, std::endl;

int main(){
    int entry_num;
    cout << "How many entries?";
    cin >> entry_num;
    cin.ignore();

    std::ofstream file("output.txt", std::ios::app);

    if (!file.is_open()){
        std::cerr << "Failed to open file" << endl;
        return 1;
    }

    for (int i = 0; i < entry_num; i++){
        std::string line;
        cout << "Enter a line of input:" << endl;
        std::getline(cin, line);

        file << line << endl;
    }
    file.close();
    return 0;
}
