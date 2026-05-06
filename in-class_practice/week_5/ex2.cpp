#include <sstream>
#include <string>
#include <iostream>

int main(){
    std::string line = "10 20 30";
    std::istringstream iss(line);
    int a, b, c;
    iss >> a >> b >> c;
    std::cout << a + b + c << std::endl;
    return 0;
}
