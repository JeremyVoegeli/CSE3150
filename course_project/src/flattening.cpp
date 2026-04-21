#include "flattening.hpp"
#include <queue>

std::vector<std::vector<int>> flatten(Graph& g){
    //initialize variables
    std::queue<int> bfs_queue;
    const auto& node_map = g.nodes();
    int max_rank = 0;

    //add all rank 0 nodes to the queue
    for(const auto& [asn, node] : node_map){
        if (node.customers.empty()){
            bfs_queue.push(asn);
            g.get(asn)->rank = 0;
        }
    }

    //queue loop
    while (!bfs_queue.empty()){
        int cur = bfs_queue.front();
        bfs_queue.pop();
        Graph::AS* cur_node = g.get(cur);

        for(int p : cur_node->providers){
            Graph::AS* p_node = g.get(p);
            int r = cur_node->rank + 1;

            if (r > p_node->rank){
                p_node->rank = r;
                if (r > max_rank){max_rank = r;}
                bfs_queue.push(p);
                //^^^ could lead to multiple enqueuing/redundant work; possible optiniaztion
            }
        }
    }

    std::vector<std::vector<int>> result(max_rank + 1);
    for(const auto& [asn, node] : node_map){
        if (node.rank >= 0)
            result[node.rank].push_back(asn);
    }
    return result;
}
