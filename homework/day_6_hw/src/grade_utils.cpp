#include <iostream>
#include "grade_utils.h"
using std::cin, std::cout, std::endl;

//returns true if student will pass, false otherwise
bool does_pass(char student_type, int grade){
    int threshold;
    if (student_type == 'u' || student_type == 'U') {threshold = 60;}
    else {threshold = 70;}
    return (grade >= threshold);
}
namespace grade_utils{
    double calculateGrade(){
        cout << "Enter student type (U for undergrad, G for grad): ";
        char c;
        cin >> c;

        cout << "Enter numeric grade: ";
        int grade;
        cin >> grade;

        if (grade < 0 || grade > 100){
            cout << "Invalid grade" << endl;
            return -1.0;
        } else if (does_pass(c, grade)){
            cout << "Status: Pass" << endl;
        }
        else cout << "Status: Fail" << endl;

        return grade;
    }
}
