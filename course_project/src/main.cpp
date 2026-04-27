#include <iostream>
#include <vector>
#include "read_data.hpp"
#include "graph.hpp"
#include "cycle_detection.hpp"
#include "flattening.hpp"
#include "propagation.hpp"
#include "output.hpp"
using std::cout, std::endl, std::string, std::vector;

int main(int argc, char* argv[]){
    //check for correct usage of program
    if (argc != 4){
        cout << "Usage: ./program.out <graph_file> <announcements_file> <rov_file>" << endl;
        return 1;
    }

    string input_file = argv[1];
    Graph g;
    try{
        load_graph(g, input_file);
        load_rov(g, argv[3]);
    } catch(const std::exception& e){
        std::cerr << e.what() << endl;
        return 1;
    }

    vector<int> cycle_output = find_cycle(g);
    if (!cycle_output.empty()){
        cout << "Cycle detected: ";
        for(size_t i = 0; i < cycle_output.size(); i++){
            cout << cycle_output[i];
            if (i < cycle_output.size() - 1){cout << " -> ";}
        }
        cout << endl;
        return 2;
    }

    try{
        load_announcements(g, argv[2]);
    } catch(const std::exception& e){
        std::cerr << e.what() << endl;
        return 1;
    }

    vector<vector<int>> flattened = flatten(g);
    propagate(g, flattened);

    try{
        write_output(g, "ribs.csv");
    } catch (const std::exception& e){
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
