#include <iostream>
#include <string>
using std::cout, std::endl;

struct Address {
    std::string street;
    std::string city;
};

struct Student {
    std::string name;
    int id;
    double gpa;
    Address address;
};

int main(){
    Student s1;
    s1.name = "Jeremy";
    s1.id = 1001;
    s1.gpa = 5.4;
    s1.address.street = "Dickhead Lane";
    s1.address.city = "Poopsville";

    Student s2;
    s2.name = "Poop Name";
    cout << s2.name << endl;
    cout << s1.name << endl;
    cout << s1.address.city << endl;
    return 0;
}
