#include <iostream>
using std::cout, std::endl;

void modify(int *p, int &r) {
    *p = *p + 5;
    r = r * 2;
    p = &r;
    *p = *p - 3;
}

int main() {
    int a = 4;
    int b = 7;

    modify(&a, b);

    cout << "a = " << a << endl;
    out << "b = " << b << endl;

    return 0;
}
