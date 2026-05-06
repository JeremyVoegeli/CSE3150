#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector;

int main(){
    vector<int> vec;
    for(int i = 0; i < 5; i++){
        vec.push_back(i);
    }
    //for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
    //    cout << *it << " ";
    //} does the same thing vvv
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
