#include <iostream>
#include <vector>

int main(){
    std::vector<int> a{};
    std::vector<int> b(5); //initializes 5 zeros
    std::vector<int> c(5, 7); //five copies of 7
    std::vector<int> d = {1, 2, 3}; //initializes a list

    std::cout << d.at(1) << std::endl; //indexing with bounds checking (not as fast as d[1])
    std::cout << a.size() << std::endl;

}
