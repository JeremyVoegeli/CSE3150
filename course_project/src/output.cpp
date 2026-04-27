#include "output.hpp"
#include "graph.hpp"
#include <fstream>

void write_output(const Graph& g, const std::string& file_path){
    std::ofstream file(file_path);

    if(!file.is_open()){
        throw std::runtime_error("Couldn't open file");
    }

    file << "asn,prefix,as_path\n";

    for(const auto& [asn, node] : g.nodes()){
        for(const auto& [prefix, announcement] : node.policy->get_local_rib()){
            std::string as_path;
            for(int v : announcement.as_path){
                as_path += std::to_string(v) + "-";
            }
            if (!as_path.empty())
                as_path.pop_back();
            file << asn << "," << prefix << "," << as_path << "\n";
        }
    }
}
