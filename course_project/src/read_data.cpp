#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "read_data.hpp"

void load_graph(Graph& g, const std::string& file_path){
    //attempt to open file from given file path
    std::ifstream file(file_path);
    if(!file.is_open()){
        throw std::runtime_error("Couldn't open file");
    }

    //iterate through every line in the input file
    std::string line;
    while (std::getline(file, line)){
        //continue if line is empty or doesn't include data
        if(line.empty() || line[0] == '#')
            continue;

        //parse line
        std::stringstream ss(line);
        std::string AS1, AS2, relationship;

        std::getline(ss, AS1, '|');
        std::getline(ss, AS2, '|');
        std::getline(ss, relationship, '|');

        try{
            int asn1 = std::stoi(AS1);
            int asn2 = std::stoi(AS2);
            int r = std::stoi(relationship);

            if (r == -1){
                g.add_provider_customer(asn1, asn2);
            } else if (r == 0){
                g.add_peer(asn1, asn2);
            }
        //continue with loop if line of data is bad
        } catch (const std::invalid_argument&){
            continue;
        } catch (const std::out_of_range&){
            continue;
        }
    }
}
