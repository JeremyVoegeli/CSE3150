#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include <sstream>

template <typename InputIterator, typename OutputIterator>
OutputIterator mycopy(
    InputIterator from,
    InputIterator to,
    OutputIterator into
){
    while (from != to){
        *into = *from;
        from++;
        into++;
    }
    return into;
};

int main(){
    std::list<int> a = {1, 2, 3, 4, 5, 6, 7};
    std::list<int> b = {0, 0, 0};
    mycopy(a.begin(), a.end(), std::back_inserter(b));
    for (const int& x : b){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
