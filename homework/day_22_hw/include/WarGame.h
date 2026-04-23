#pragma once
#include <string>
#include "Deck.h"
#include "FileWriter.h"

class WarGame{
private:
    Deck pa_;
    Deck pb_;
    int round_;
    FileWriter fw_;

    void playRound();
public:
    WarGame(Deck d, std::string output_path): round_(1), fw_(output_path){
        auto [a, b] = d.split();
        pa_ = std::move(a);
        pb_ = std::move(b);
    }

    void play();
};
