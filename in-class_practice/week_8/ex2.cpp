#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

int main(){
    int x = 5;
    //const int* px = &x;
    int* const px = &x;
    y = 7;
    cout << "px=" << px << endl;
    cout << "*px=" << *px << endl;
    return 0;
}
