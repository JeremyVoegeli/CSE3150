#pragma once
#include <deque>
#include <memory>
#include <iostream>
#include <utility>
#include "Card.h"

class Deck{
private:
    std::deque<std::unique_ptr<Card>> cards_;
public:
    //default constructor
    Deck() = default;

    //move constructors
    Deck (Deck&& other) = default;
    Deck& operator=(Deck&& other) = default;

    //copy constructors
    Deck (const Deck&) = delete;
    Deck& operator=(const Deck&) = delete;

    size_t size() const;
    bool empty() const;

    auto begin();
    auto begin() const;

    auto end();
    auto end() const;

    std::unique_ptr<Card> draw();
    void addToBottom(std::unique_ptr<Card> c);
    std::pair<Deck, Deck> split();

    friend std::ostream& operator<<(std::ostream& os, const Deck& d);
};
