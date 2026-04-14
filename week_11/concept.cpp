#include <iostream>
#include <iterator>
#include <concepts>

template <class T>
concept Comparable =
    requires(T a, T b) {
        {a > b}
        -> std::convertible_to<bool>;
    };

template <Comparable T>
T max(T a, T b){
    return a > b ? a : b;
}

int main(){
    return 0;
}
