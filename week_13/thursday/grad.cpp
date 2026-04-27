#include <ostream>
#include <iostream>
#include <string>

class UGrad{
protected:
    std::string name_;
    double grade_;
public:
    UGrad(const std::string& n, double g):
        name_(n), grade_(g) {}
    const char letterGrade() const;
    friend std::ostream& operator<<(std::ostream& os, const UGrad& ug){
        return os << ug.name_ << "(UG)=" << ug.grade_ << ":" << ug.letterGrade();
    }
};

class Grad : public UGrad{
public:
    Grad(const std::string& n, double g) : UGrad(n, g) {}
    const char letterGrade() const;
    friend std::ostream& operator<<(std::ostream& os, const Grad g){
        return os << g.name_ << "(G)=" << g.grade_ << ":" << g.letterGrade();
    }
};

const char UGrad::letterGrade() const {
    if (80 < grade_ && grade_ <= 100){
        return 'A';
    } else {
        return 'F';
    }
}

const char Grad::letterGrade() const {
    if (95 < grade_ && grade_ <= 100){
        return 'A';
    } else {
        return 'F';
    }
}
