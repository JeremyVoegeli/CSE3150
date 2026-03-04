#include <iostream>
#include <vector>

int main(){
    std::vector<int> v;
    std::cout << v.size() << std::endl;

    for (int i = 0; i < 10; ++i){
        v.push_back(i);
        std::cout << "size=" << v.size() << " capacity=" << v.capacity() << std::endl;
    }
    return 0;
}
