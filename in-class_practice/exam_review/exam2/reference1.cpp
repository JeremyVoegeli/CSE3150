#include <iostream>
using std::cout, std::endl;

void normalize(int &a, int &b){
    if (a > b){
        int temp = a;
        a = b;
        b = temp;
    }
}

void clamp(int &x, int min, int max){
    if (x < min){x = min;}
    else if (x > max){x = max;}
}

int main(){
    int x = 20;
    int y = 10;

    normalize(x, y);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    clamp(x, 0, 5);
    cout << "Now, x = " << x << endl;
    return 0;
}
