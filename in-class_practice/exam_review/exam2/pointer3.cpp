#include <iostream>
using std::cout, std::endl;

void reverseArray(int* arr, int size){
    int* start = arr;
    int* end = arr + size - 1;

    while (start < end){
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int sumArray(int* arr, int size){
    int sum = 0;
    for(int* i = arr; i <= arr + size - 1; i++){
        sum += *arr;
    }
    return sum;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    reverseArray(arr, 5);

    for(int i : arr){
        cout << i << endl;
    }

    int sum = sumArray(arr, 5);
    cout << "Sum = " << sum << endl;
    return 0;
}
