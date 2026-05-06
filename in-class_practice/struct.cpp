#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

struct Student {
    string name;
    int id;
    double gpa;
};

int main(){
    Student s1;

    cout << "Student info:" << endl;
    cout << "Name: ";
    cin >> s1.name;
    cout << "ID: ";
    cin >> s1.id;
    cout << "GPA: ";
    cin >> s1.gpa;
    return 0;
}
