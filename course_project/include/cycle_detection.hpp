#pragma once
#include <vector>
#include "graph.hpp"

enum class VisitState{
    Unvisited,
    Visiting,
    Done
};

bool dfs(
    const Graph& g,
    Graph::AS* n,
    std::unordered_map<int, VisitState>& visited,
    std::vector<int>& path
);

std::vector<int> find_cycle(const Graph& g);