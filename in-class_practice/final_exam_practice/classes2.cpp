#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

class Vehicle{
private:
    string make;
    int year;
public:
    Vehicle() : make("Default"), year(2000) {}
    Vehicle(string m, int y) : make(m), year(y) {}

    virtual ~Vehicle(){
        cout << "Destructing Vehicle" << endl;
    }

    virtual string getFuelType() const = 0;
    virtual void describe() const {
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
    };

    friend void printMake(const Vehicle& v);
};

void printMake(const Vehicle& v){
    cout << "Make: " << v.make << endl;
}

class GasVehicle : public Vehicle{
private:
    double engineSize;
public:
    GasVehicle() : Vehicle(), engineSize(4.0) {
        cout << "Gas Vehicle constructor" << endl;
    }
    GasVehicle(string m, int y, double e) : Vehicle(m, y), engineSize(e) {
        cout << "Gas Vehicle constructor" << endl;
    }
    ~GasVehicle(){
        cout << "Gas Vehicle destructor" << endl;
    }

    string getFuelType() const override {
        return "Gasoline";
    }

    void describe() const override{
        Vehicle::describe();
        cout << "Engine Size: " << engineSize << endl;
    }
};

class ElectricVehicle : public Vehicle{
private:
    int batteryRange;
public:
    ElectricVehicle() : Vehicle(), batteryRange(100) {
        cout << "Electric Vehicle constructor" << endl;
    }
    ElectricVehicle(string m, int y, int r) : Vehicle(m, y), batteryRange(r) {
        cout << "Electric Vehicle constructor" << endl;
    }
    ~ElectricVehicle(){
        cout << "Electric Vehicle destructor" << endl;
    }
    string getFuelType() const override {
        return "Electric";
    }

    void describe() const override {
        Vehicle::describe();
        cout << "Battery Range: " << batteryRange << endl;
    }
};

int main(){
    GasVehicle g ("Ferarri", 2003, 8.5);
    ElectricVehicle e ("Tesla", 2016, 70);

    Vehicle* g_ptr = &g;
    Vehicle* e_ptr = &e;

    g_ptr->describe();
    g_ptr->getFuelType();

    e_ptr->describe();
    e_ptr->getFuelType();

    printMake(*g_ptr);
    printMake(*e_ptr);

    return 0;
}