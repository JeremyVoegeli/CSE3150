#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "student.h"
using std::cout, std::endl;

int main(){
    auto sp = std::make_shared<Student>();
    sp->read(std::cin);
    sp->print(std::cout);
    return 0;
}
