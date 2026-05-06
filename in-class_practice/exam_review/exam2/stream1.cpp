#include <iostream>
#include <sstream>
#include <vector>
using std::cin, std::cout, std::endl;

int main(){
    std::string line;
    cout << "Enter several integers on one line separated by spaces:" << endl;
    std::getline(cin, line);
    std::istringstream ss(line);

    int v;
    std::vector<int> vec;
    while(ss >> v){
    vec.push_back(v);
    }

    int sum = 0;
    for(int i : vec){
        sum += i;
        cout << i << endl;
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
