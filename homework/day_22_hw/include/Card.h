#pragma once
#include <iostream>

class Card {
public:
    virtual int value() const = 0;
    virtual void print(std::ostream& os) const = 0;

    virtual bool operator<(const Card& c);
    virtual bool operator==(const Card& c) const;

    friend std::ostream& operator<<(std::ostream& os, const Card& c);

    virtual ~Card() = 0;
};
