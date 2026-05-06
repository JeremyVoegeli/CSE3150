#include <iostream>
#include "student.h"

void Student::read(std::istream& is){
    is >> name_ >> mt_ >> final_;
    int number_hw = 0;
    is >> number_hw;
    for(int i = 0; i < number_hw; ++i){
        int v;
        is >> v;
        homeworks_.push_back(v);
    }
}

void Student::print(std::ostream& os){
    os << "Name: " << name_ << "[" << mt_ << "," << final_ << "]\n";
    for(int v : homeworks_)
        os << '\t' << v << std::endl;
}
