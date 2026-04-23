#include "JokerCard.h"

int JokerCard::value() const{
    return 14;
}

void JokerCard::print(std::ostream& os) const{
    os << color_ << " Joker";
}
