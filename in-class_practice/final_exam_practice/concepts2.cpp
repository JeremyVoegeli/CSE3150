//STARTER CODE WRITTEN BY CLAUDE
#include <iostream>
#include <concepts>
#include <string>
using std::cout, std::endl, std::string;

// TODO 1: Define a concept "Numeric" that requires:
//         - T supports + and - operators
//         - T supports * and / operators
//         - All operators return something convertible to T
template <typename T>
concept Numeric = requires(T a, T b){
    {a + b} -> std::convertible_to<T>;
    {a - b} -> std::convertible_to<T>;
    {a * b} -> std::convertible_to<T>;
    {a / b} -> std::convertible_to<T>;
};

// TODO 2: Define a concept "Describable" that requires:
//         - T has a method describe() that returns a string
template<typename T>
concept Describable = requires(T a){
    {a.describe()} -> std::convertible_to<string>;
};

// TODO 3: Define a concept "NumericAndComparable" that combines:
//         - Numeric
//         - T supports < and > returning bool
//         - (hint: you can combine an existing concept with extra requires!)
template <typename T>
concept NumericAndComparable = Numeric<T> && requires (T a, T b){
    {a > b} -> std::convertible_to<bool>;
    {a < b} -> std::convertible_to<bool>;
};

// Apply TODO 1 here
template <Numeric T>
T sum(T a, T b, T c) {
    return a + b + c;
}

// Apply TODO 2 here
template <Describable T>
void printDescription(T a) {
    cout << a.describe() << endl;
}

// Apply TODO 3 here
template <NumericAndComparable T>
T clamp(T val, T low, T high) {
    if (val < low) return low;
    if (val > high) return high;
    return val;
}

// These classes are provided for you to test with — don't modify them!
class Animal {
private:
    string name;
    string sound;
public:
    Animal(string n, string s) : name(n), sound(s) {}
    string describe() const { return name + " says " + sound; }
};

class Robot {
public:
    string describe() const { return "Beep boop."; }
};

int main(){
    cout << sum(1, 2, 3) << endl;
    cout << sum(1.5, 2.5, 3.5) << endl;

    printDescription(Animal("Cat", "meow"));
    printDescription(Robot());

    cout << clamp(15, 0, 10) << endl;
    cout << clamp(5, 0, 10) << endl;

    return 0;
}