
#include <iostream>
#include <cstring>   // for strlen, strcpy
#include <string>
#include "solution.h"
using std::cout, std::endl, std::cin, std::string;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char** names_arr = new char*[capacity];
    double* gpa_arr = new double[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                double gpa;

                cout << "Enter student name:" << endl;
                cin.ignore();
                std::getline(cin, name);
                cout << "Enter student GPA:" << endl;
                cin >> gpa;

                char* name_ptr = new char[name.length() + 1];
                std::strcpy(name_ptr, name.c_str());

                solution::addStudent(name_ptr, gpa, names_arr, gpa_arr, size, capacity);
                cout << endl;
                break;
            }
            case 2: {
                double new_gpa;
                int student_idx;

                cout << "Enter index for student:" << endl;
                cin >> student_idx;
                cout << "Enter new GPA:" << endl;
                cin >> new_gpa;

                solution::updateGPA(gpa_arr + student_idx, new_gpa);
                break;
            }
            case 3: {
                for(int i = 0; i < size; i++){
                    solution::printStudent(*(names_arr + i), *(gpa_arr + i));
                }
                break;
            }
            case 4: {
                double avg = solution::averageGPA(gpa_arr, size);

                if (avg >= 0){
                    cout << "Average GPA:" << endl;
                    cout << avg << endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    for (int i = 0; i < size; i++){
        delete *(names_arr + i);
    }
    delete[] names_arr;
    delete[] gpa_arr;
    return 0;
}
