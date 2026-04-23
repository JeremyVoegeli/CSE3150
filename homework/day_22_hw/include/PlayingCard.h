#pragma once
#include "Card.h"
#include <string>

class PlayingCard : public Card {
protected:
    std::string suit_;
    int rank_;
public:
    PlayingCard(std::string suit, int rank) : suit_(suit), rank_(rank) {}

    std::string rankToString(int rank) const;
    int value() const override;
    void print(std::ostream& os) const override;
};
