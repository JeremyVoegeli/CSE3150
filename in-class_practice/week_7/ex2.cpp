#include <iostream>
using std::cout, std::endl;

int main(){
    int* px = new int[10]; //array on the HEAP

    for (int* cx = px; cx < px + 10; cx++){
        *cx = cx - px; //gets how far apart the 2 pointers are
    }

    for (int i = 0; i < 10; ++i){ //values stored on the STACK
        cout << "px[" << i << "]=" << px[i] << endl;
    }
    delete[] px;
}
