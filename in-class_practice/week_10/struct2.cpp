#include <iostream>
#include <string>
using std::cout, std::endl;

class Rectangle {
    double width_;
public:
    Rectangle(double width, double height){
        width_ = width;
        height_ = height;
    }
    double height_;
    double area() const;
    void setWidth(double width_);
    double getWidth() const;
};

double Rectangle::area() const {
    return width_ * height_;
}

void Rectangle::setWidth(double width){
    width_ = width;
}

double Rectangle::getWidth() const {
    return width_;
}

int main(){
    Rectangle r(5, 2);
    cout << r.getWidth() << endl;
    return 0;
}
