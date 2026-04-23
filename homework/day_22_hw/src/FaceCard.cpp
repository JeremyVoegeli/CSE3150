#include "FaceCard.h"

void FaceCard::print(std::ostream& os) const{
    std::string string_rank;
    switch(value()){
        case(11):
            string_rank = "Jack";
            break;
        case(12):
            string_rank = "Queen";
            break;
        case(13):
            string_rank = "King";
            break;
        default:
            string_rank = rankToString(rank_);
            break;
    }

    os << string_rank << " of " << suit_;
}
