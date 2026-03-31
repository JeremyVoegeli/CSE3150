#include "solution.h"
#include <iostream>
using std::cout, std::endl;

namespace solution{
    void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
        try{
            if (size + 1 > capacity){
                throw " List full";
            }
            *(names + size) = name;
            *(gpas + size) = gpa;
            size++;
        }catch(const char* msg){
            cout << "Error: " << msg << endl;
        }
    }

    void updateGPA(double* gpaPtr, double newGpa){
        *gpaPtr = newGpa;
    }

    void printStudent(const char* name, const double& gpa){
        cout << "Name: ";
        int i = 0;
        while(*(name + i) != '\0'){
            cout << *(name + i);
            i++;
        }
        cout << endl;
        cout << "GPA: " << gpa << endl << endl;
    }

    double averageGPA(const double gpas[], int size){
        try{
            if (size == 0){
                throw "No students added.";
            }
            double sum = 0.0;
            for(int i = 0; i < size; i++){
                sum += *(gpas + i);
            }

            double avg = sum / size;
            return static_cast<int>(avg);
        }catch(const char* msg){
            cout << "Error: " << msg << endl;
            return -1;
        }
    }
}
