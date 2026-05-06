#include <iostream>
using std::cout, std::endl;

int main(){
    int x = 5;
    int* arr = new int[x];
    arr[0] = 10;
    arr[1] = 20;
    cout << arr[0] << endl;
    delete[] arr;
    return 0;
}
