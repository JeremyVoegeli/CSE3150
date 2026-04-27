#pragma once
#include "graph.hpp"
#include <vector>

void propagate(Graph& g, const std::vector<std::vector<int>>& ranks);
