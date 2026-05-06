#include <iostream>
using std::cout, std::endl;

void swapValues(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void addTen(int* num){
    *num += 10;
}

int main(){
    int x = 5;
    int y = 10;

    swapValues(&x, &y);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    addTen(&x);

    cout << "Now, x = " << x << endl;
    return 0;
}
