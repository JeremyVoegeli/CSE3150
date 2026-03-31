#include <iostream>
#include <vector>
#include <climits>
using std::cin, std::cout, std::endl, std::vector;

int find_largest(vector<int> v){
    int max = INT_MIN;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > max){max = v[i];}
    }
    return max;
}

int main(){
    int count;
    cout << "How many numbers will you enter? ";
    cin >> count;

    vector<int> v;
    cout << "Enter the numbers:" << endl;
    for(int i = 0; i < count; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    cout << "The largest number is: " << find_largest(v) << endl;
    return 0;
}
