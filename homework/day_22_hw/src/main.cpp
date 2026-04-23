#include "FileReader.h"
#include "FileWriter.h"
#include "Deck.h"
#include "WarGame.h"
#include <iostream>
using std::cout, std::endl;

int main(int argc, char* argv[]){
    if (argc != 3){
        std::cerr << "Usage: ./war_game <input_csv> <output_csv>" << endl;
        return 1;
    }
    try{
        Deck d = FileReader::readDeckFromCSV(argv[1]);
        WarGame game = WarGame(std::move(d), argv[2]);
        game.play();
    } catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
