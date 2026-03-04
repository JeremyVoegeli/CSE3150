#include <iostream>
using std::cout, std::endl, std::cin;

//Calculates n! using a for loop
int forFactorial(int n){
    int result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

//Calculates nth number in Fibonacci sequence using a for loop
int forFibonacci(int n){
    int a = 0;
    int b = 1;

    if (n == 1) {return a;}
    else if (n == 2) {return b;}
    else {
        int c;
        for(int i = 3; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

//Caculates sum of all integers, counts how many are even
int range_based_practice(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int even_count = 0;
    int sum = 0;
    for(int i : arr){
        if (i % 2 == 0) {even_count++;}
        sum += i;
    }
    cout << "Sum: " << sum << endl;
    cout << "Even count: " << even_count << endl;
    return 0;
}

int main(){
    range_based_practice();
    return 0;
}
