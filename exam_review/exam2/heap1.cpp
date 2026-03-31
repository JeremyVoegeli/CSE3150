#include <iostream>
using std::cin, std::cout, std::endl;

int findMax(int* arr, int size){
    int max = *arr;
    for(int i = 1; i < size; i++){
        if(*(arr + i) > max){max = *(arr + i);}
    }
    return max;
}

int findMin(int* arr, int size){
    int min = *arr;
    for(int i = 1; i < size; i++){
        if(*(arr + i) < min){min = *(arr + i);}
    }
    return min;
}

double average(int* arr, int size){
    double avg = 0;
    for(int i = 0; i < size; i++){
        avg += *(arr + i);
    }

    avg = avg / size;
    return avg;
}

int main(){
    //prompts user for number count
    int count;
    cout << "How many numbers do you want to store? ";
    cin >> count;

    //creates new array on heap, asks user for numbers to fill array
    int* arr = new int[count];

    for(int i = 0; i < count; i++){
        int num;
        cout << "Enter number " << (i + 1) << ": ";
        cin >> num;
        *(arr + i) = num;
    }

    //call additional functions
    cout << "Max: " << findMax(arr, count) << endl;
    cout << "Min: " << findMin(arr, count) << endl;
    cout << "Average: " << average(arr, count) << endl;
    cout << endl;

    //prints original array
    cout << "Original: ";
    for(int i = 0; i < count; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;

    //allocates and prints reversed array
    int* reversed = new int[count];
    for(int i = 0; i < count; i++){
        *(reversed + i) = *(arr + count - 1 - i);
    }

    cout << "Reversed: ";
    for(int i = 0; i < count; i++){
        cout << *(reversed + i) << " ";
    }
    cout << endl;

    //deletes allocated memory, returns
    delete[] arr;
    delete[] reversed;
    return 0;
}
