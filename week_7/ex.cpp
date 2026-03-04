#include <iostream>

using std::cout, std::endl;

int main(){
    int* px = new int[10]; //10 "blocks" of memory  (with respect to an integer)
    *px = 20; //first item in array is now 20
    cout << "*px=" << *px << endl; //"Item at px is"
    cout << "px=" << px << endl; //"actual address is"
    delete[] px; //frees memory from the heap
}
