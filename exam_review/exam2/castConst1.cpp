#include <iostream>
using std::cin, std::cout, std::endl;

double CtoF(const double c){
    return c * static_cast<double>(9) / 5 + 32;
}

double average_temp(const double* arr, const int size){
    double avg = 0;
    for(int i = 0; i < size; i++){
        avg += *(arr + i);
    }
    avg = avg / static_cast<double>(size);
    return avg;
}

int num_hot_days(const double* arr, const int size, const double threshold){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(*(arr + i) > threshold){count++;}
    }
    return count;
}

int main(){
    int num_readings;
    cout << "How many readings were recorded? ";
    cin >> num_readings;

    double* arr = new double[num_readings];

    for(int i = 0; i < num_readings; i++){
        double reading;
        cout << "Enter reading " << (i + 1) << ": ";
        cin >> reading;
        *(arr + i) = reading;
    }
    cout << endl;

    double avg_c = average_temp(arr, num_readings);
    cout << "Average Celsius: " << avg_c << endl;
    cout << "Average Fahrenheit: " << CtoF(avg_c) << endl;
    const double THRESHOLD = 22;
    cout << "Days above " << THRESHOLD << "C: " << num_hot_days(arr, num_readings, THRESHOLD) << endl;
    return 0;
}
