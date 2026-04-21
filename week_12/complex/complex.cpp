#include "complex.hpp"

void Complex::print(std::ostream& os){
    os << '(' << real_ << '+' << imag_ << "i)";
}
