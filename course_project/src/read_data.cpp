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

void load_rov(Graph& g, const std::string& file_path){
    //attempt to open file
    std::ifstream file(file_path);
    if(!file.is_open()){
        throw std::runtime_error("Couldn't open file");
    }

    std::string asn_string;
    while (file >> asn_string){
        try{
            int asn_int = std::stoi(asn_string);
            if (g.contains(asn_int)){
                g.get(asn_int)->set_policy(std::make_unique<ROV>(asn_int));
            }
        } catch (const std::invalid_argument&){
            continue;
        } catch (const std::out_of_range&){
            continue;
        }
    }
}

void load_announcements(Graph& g, const std::string& file_path){
    std::ifstream file(file_path);
    if(!file.is_open()){
        throw std::runtime_error("Couldn't open file");
    }

    bool header = true;
    std::string line;

    while (std::getline(file, line)){
        if(header){
            header = false;
            continue;
        }

        std::string asn, prefix, rov_invalid;

        try{
            std::stringstream ss(line);
            std::getline(ss, asn, ',');
            std::getline(ss, prefix, ',');
            std::getline(ss, rov_invalid);

            int int_asn = std::stoi(asn);
            Graph::AS* AS_node = g.get(int_asn);
            if (!AS_node) continue;
            Announcement a(prefix);
            a.as_path.push_back(int_asn);
            a.next_hop_asn = int_asn;
            a.received_from = Relationship::Origin;
            if (rov_invalid == "true"){a.rov_invalid = true;}
            else {a.rov_invalid = false;}
            AS_node->policy->get_local_rib()[prefix] = a;
        } catch (const std::invalid_argument&){
            continue;
        } catch (const std::out_of_range&){
            continue;
        }
    }
}
