#pragma once
#include <iostream>

class Point{
    double x_;
    double y_;
public:
    Point() {x_ = y_ = 0;} //default constructor
    Point(double x, double y): x_(x), y_(y) {} //custom constructor
    Point(const Point& p): x_(p.getX()), y_(p.getY()) {} //copy constructor

    double getX() const {return x_;}
    double getY() const {return y_;}

    void set(double x, double y){
        x_ = x;
        y_ = y;
    }

    Point& operator=(const Point& p){
        x_ = p.getX();
        y_ = p.getY();
        return *this;
    }

    friend Point operator+(const Point& p1, const Point& p2){
        return Point(
            p1.getX() + p2.getX(),
            p1.getY() + p2.getY()
        );
    }

    friend Point operator*(const Point& p, double s){
        return Point(
            p.getX() * s,
            p.getY() * s
        );
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p){
        os << "(" << p.getX() << ", " << p.getY() << ")";
        return os;
    }
};
