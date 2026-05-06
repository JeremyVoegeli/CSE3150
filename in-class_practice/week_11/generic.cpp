#include <iostream>
#include <stack>
#include <vector>
using std::cout, std::endl, std::stack;

//using T makes the function generic to multiple types
template <class T>
T sum(const std::vector<T>& vec){
    T ttl{};
    for(T x : vec)
        ttl += x;
    return ttl;
}

int main(){
    std::vector<int> vec;
    for (int i = 0; i < 5; i++){
        vec.push_back(i);
    }
    for (int v : vec){
        cout << "val=" << v << endl;
    }
    return 0;
}
