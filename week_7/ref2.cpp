#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

int main(){
    int a = 5;
    int& r = a; //r is an ALIAS for a
    r = 10;
    cout << a << endl;
    cout << r << endl;
    return 0;
}
