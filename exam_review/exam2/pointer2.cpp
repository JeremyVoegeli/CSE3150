#include <iostream>
using std::cout, std::endl;

void rotateValues(int* a, int* b, int* c){
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void order(int* a, int* b){
    if (*a > *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main(){
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;

    rotateValues(&num1, &num2, &num3);

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num3 = " << num3 << endl;

    return 0;
}
