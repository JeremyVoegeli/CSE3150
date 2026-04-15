#include <vector>

class Student {
public:
    Student() {mt_ = final_ = 0;}
    Student(const std::string& s):
        name_(s),
        mt_(0),
        final_(0) {}
    Student(const Student& s2):
        name_(s2.name_),
        mt_(s2.mt_),
        final_(s2.final_),
        homeworks_(s2.homeworks_) {}
    Student(Student&& other):
        name_(std::move(other.name_)),
        mt_(other.mt_),
        final_(other.final_),
        homeworks_(std::move(other.homeworks_)) {}
    std::string name_;
    double mt_, final_;
    std::vector<double> homeworks_;
    void read(std::istream& is);
    void print(std::ostream& os);
};
