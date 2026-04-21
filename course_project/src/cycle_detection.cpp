#include "cycle_detection.hpp"
#include <unordered_map>
#include <algorithm>

bool dfs(
    const Graph& g,
    const Graph::AS* node,
    std::unordered_map<int, VisitState>& visited,
    std::vector<int>& path,
    std::vector<int>& result
){
    int cur_asn = node->asn();

    //Mark current node as "Visiting" in map
    visited[cur_asn] = VisitState::Visiting;

    //add current node to the path
    path.push_back(cur_asn);

    //iterate over providers
    for (int p : node->providers){
        auto status = visited[p];

        //cycle has been found:
        if (status == VisitState::Visiting){
            auto starting_it = std::find(path.begin(), path.end(), p);
            std::copy(starting_it, path.end(), std::back_inserter(result));
            result.push_back(p);
            return true;

        //unvisited node found
        } else if (status == VisitState::Unvisited){
             const Graph::AS* p_node = g.get(p);
            if (p_node && dfs(g, p_node, visited, path, result))
                return true;
        }
    }

    //mark current node as "Done"
    visited[cur_asn] = VisitState::Done;
    path.pop_back();
    return false;
}

std::vector<int> find_cycle(const Graph& g){
    //initialize every node as unvisited in the unordered map
    std::unordered_map<int, VisitState> visit_map;

    //initialize all values to be unvisited
    for (const auto& [asn, node] : g.nodes()){
        visit_map.insert({asn, VisitState::Unvisited});
    }
    //initialize empty result and path vectors
    std::vector<int> path;
    std::vector<int> result;
    for (const auto& [asn, _] : visit_map){
        if (visit_map[asn] == VisitState::Unvisited){
            if (dfs(g, g.get(asn), visit_map, path, result)){
                return result;
            }
        }
    }

    return std::vector<int>();
}
