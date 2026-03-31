#include <iostream>
#include <vector>
using std::cin, std::cout, std::endl, std::vector;

int main(){
    int a, b, c, d, e;
    cout << "Enter 5 numbers:" << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;

    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    int sum = 0;
    cout << "The numbers in the vector are:" << endl;
    for (int i = 0; i < 5; i++){
        cout << v[i] << " ";
        sum += v[i];
    }
    cout << endl;
    cout << "Sum = " << sum << endl;
    return 0;
}
