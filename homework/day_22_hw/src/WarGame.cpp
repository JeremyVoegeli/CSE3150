#include "WarGame.h"
#include <iostream>
#include <memory>

void WarGame::playRound(){
    std::unique_ptr<Card> pa_draw = std::move(pa_.draw());
    std::unique_ptr<Card> pb_draw = std::move(pb_.draw());

    if(!pa_draw || !pb_draw){
        return;
    }

    std::cout << "Player A plays: " << *pa_draw << std::endl;
    std::cout << "Player B plays: " << *pb_draw << std::endl;

    //Player A wins:
    if (*pb_draw < *pa_draw || *pb_draw == *pa_draw){
        pa_.addToBottom(std::move(pa_draw));
        pa_.addToBottom(std::move(pb_draw));
    //Player B wins:
    } else {
        pb_.addToBottom(std::move(pb_draw));
        pb_.addToBottom(std::move(pa_draw));
    }
}

void WarGame::play(){
    std::cout << "Starting War" << std::endl;

    while (!pa_.empty() && !pb_.empty()){
        std::cout << "Round " << round_ << std::endl;
        playRound();
        fw_.writeRound(round_, pa_, pb_);
        round_++;
    }
    std::cout << "Game Over" << std::endl;

    //player A wins
    if(!pa_.empty() && pb_.empty()){
        std::cout << "Player A wins with " << pa_.size() << "cards!" << std::endl;
    } else if(pa_.empty() && !pb_.empty()){
        std::cout << "Player B wins with " << pb_.size() << " cards!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }
}
