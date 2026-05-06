#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <list>

template <class InputIterator, class T>
InputIterator my_find(
    InputIterator from,
    InputIterator to,
    const T& target
){
    while(from != to){
        if(*from == target)
            return from;
        ++from;
    }
    return from;
}

int main(){
    std::list<int> vec = {1, 2, 3, 4, 5, 6, 7};
    auto at = my_find(vec.begin(), vec.end(), 6);
    bool found = (at != vec.end());
    std::cout << "Found? " << found << std::endl;
    if (found)
        std::cout << "value=" << *at << std::endl;
    return 0;
}
