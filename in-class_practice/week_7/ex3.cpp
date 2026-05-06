#include <iostream>
using std::cout, std::endl;

int main(){
    int* a = new int(10);
    int* b = new int(20);
    int* c = new int(30);

    int* arr[3] = {a, b, c};
    for (int i = 0; i < 3; ++i){
        cout << "px[" << i << "]=" << *arr[i] << endl;
    }
    for (int i = 0; i < 3; ++i){
        delete arr[i];
    }
    return 0;
}
