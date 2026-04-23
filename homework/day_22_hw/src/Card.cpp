#include "Card.h"

bool Card::operator<(const Card& c){
    return value() < c.value();
}

bool Card::operator==(const Card& c) const{
    return value() == c.value();
}

std::ostream& operator<<(std::ostream& os, const Card& c){
    c.print(os);
    return os;
}

Card::~Card() {}
