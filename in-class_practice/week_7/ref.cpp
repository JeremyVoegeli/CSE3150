#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector;

void double_vector(vector<int>& v){
    for (int i = 0; i < v.size(); i++){
        v[i] *= 2;
    }
}


int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    double_vector(v);
    for (size_t i=0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    return 0;
}
