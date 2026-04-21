#include <iostream>
#include <vector>
#include "read_data.hpp"
#include "graph.hpp"
#include "cycle_detection.hpp"
#include "flattening.hpp"
using std::cout, std::endl, std::string, std::vector;

int main(int argc, char* argv[]){
    //check for correct usage of program
    if (argc < 2){
        cout << "Usage: ./program.out <input_file_path>" << endl;
        return 1;
    }

    string input_file = argv[1];
    Graph g;
    try{
        load_graph(g, input_file);
    } catch(const std::exception& e){
        std::cerr << e.what() << endl;
        return 1;
    }

    vector<int> cycle_output = find_cycle(g);
    if (cycle_output.empty()){
        cout << "No cycles in input data." << endl;
    } else {
        cout << "Cycle detected: ";
        for(size_t i = 0; i < cycle_output.size(); i++){
            cout << cycle_output[i];
            if (i < cycle_output.size() - 1){cout << " -> ";}
        }
        cout << endl;
        return 2;
    }

    vector<vector<int>> flattened = flatten(g);
    cout << "Total number of ranks: " << flattened.size() << endl;
    cout << "Number of ASes at rank 0: " << flattened[0].size() << endl;
    return 0;
}
