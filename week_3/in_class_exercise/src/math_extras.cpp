#include "math_extras.hpp"

namespace MathExtras{
    int factorial(int n){
        if (n <= 1){return 1;}
        else{return n * factorial(n - 1);}
    }
}
