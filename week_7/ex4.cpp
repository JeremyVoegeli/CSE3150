#include <iostream>
using std::cout, std::endl;

int main(){
    int** arr = new int*[3];
    for (int i = 0; i < 3, i++){
        arr[i] = new int(i * 10);
    }

    for (int i = 0; i < 3; i++){
        cout << "px[" << i << "]=" << *arr[i] << endl;
    }
    delete[] arr;
}
