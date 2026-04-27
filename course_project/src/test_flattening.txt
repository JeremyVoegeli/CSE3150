#include "flattening.hpp"
#include "graph.hpp"
#include <cassert>
#include <iostream>

// ─── Basic Cases ─────────────────────────────────────────────────────────────

void test_single_node(){
    Graph g;
    g.create(1);
    auto result = flatten(g);

    // single node with no customers is rank 0
    assert(result.size() == 1);
    assert(result[0].size() == 1);
    assert(result[0][0] == 1);

    std::cout << "test_single_node passed\n";
}

void test_simple_chain(){
    Graph g;
    // 1 is provider of 2, 2 is provider of 3
    // rank 0: node 3, rank 1: node 2, rank 2: node 1
    g.add_provider_customer(2, 3);
    g.add_provider_customer(1, 2);
    auto result = flatten(g);

    assert(result.size() == 3);
    assert(g.get(3)->rank == 0);
    assert(g.get(2)->rank == 1);
    assert(g.get(1)->rank == 2);

    std::cout << "test_simple_chain passed\n";
}

void test_multiple_rank_zero_nodes(){
    Graph g;
    // nodes 2, 3, 4 are all customers of node 1
    // rank 0: nodes 2, 3, 4 — rank 1: node 1
    g.add_provider_customer(1, 2);
    g.add_provider_customer(1, 3);
    g.add_provider_customer(1, 4);
    auto result = flatten(g);

    assert(result.size() == 2);
    assert(result[0].size() == 3);
    assert(result[1].size() == 1);
    assert(g.get(1)->rank == 1);
    assert(g.get(2)->rank == 0);
    assert(g.get(3)->rank == 0);
    assert(g.get(4)->rank == 0);

    std::cout << "test_multiple_rank_zero_nodes passed\n";
}

// ─── Diamond / Multi-Path Cases ──────────────────────────────────────────────

void test_diamond(){
    Graph g;
    // diamond: 1 is provider of 2 and 3, both 2 and 3 are providers of 4
    // rank 0: node 4
    // rank 1: nodes 2 and 3
    // rank 2: node 1
    g.add_provider_customer(1, 2);
    g.add_provider_customer(1, 3);
    g.add_provider_customer(2, 4);
    g.add_provider_customer(3, 4);
    auto result = flatten(g);

    assert(result.size() == 3);
    assert(g.get(4)->rank == 0);
    assert(g.get(2)->rank == 1);
    assert(g.get(3)->rank == 1);
    assert(g.get(1)->rank == 2);

    std::cout << "test_diamond passed\n";
}

void test_unequal_paths_to_same_node(){
    Graph g;
    // node 4 is reachable from node 1 via two paths of different lengths:
    // short path: 1 -> 4 (would give rank 1)
    // long path:  1 -> 2 -> 3 -> 4 (would give rank 3)
    // node 1 should get the highest rank (3)
    g.add_provider_customer(1, 4);
    g.add_provider_customer(1, 2);
    g.add_provider_customer(2, 3);
    g.add_provider_customer(3, 4);
    auto result = flatten(g);

    // node 1 should have rank 3 (longest path wins)
    assert(g.get(4)->rank == 0);
    assert(g.get(3)->rank == 1);
    assert(g.get(2)->rank == 2);
    assert(g.get(1)->rank == 3);

    std::cout << "test_unequal_paths_to_same_node passed\n";
}

// ─── Disconnected Components ─────────────────────────────────────────────────

void test_two_disconnected_chains(){
    Graph g;
    // chain 1: 1 -> 2
    // chain 2: 3 -> 4
    g.add_provider_customer(1, 2);
    g.add_provider_customer(3, 4);
    auto result = flatten(g);

    assert(result.size() == 2);
    assert(g.get(2)->rank == 0);
    assert(g.get(4)->rank == 0);
    assert(g.get(1)->rank == 1);
    assert(g.get(3)->rank == 1);
    assert(result[0].size() == 2); // nodes 2 and 4 at rank 0
    assert(result[1].size() == 2); // nodes 1 and 3 at rank 1

    std::cout << "test_two_disconnected_chains passed\n";
}

void test_peers_dont_affect_rank(){
    Graph g;
    // peers should not influence propagation rank at all
    g.add_provider_customer(1, 2);
    g.add_peer(1, 3);
    g.create(3);
    auto result = flatten(g);

    assert(g.get(2)->rank == 0);
    assert(g.get(1)->rank == 1);
    // node 3 has no customers so it is rank 0
    assert(g.get(3)->rank == 0);

    std::cout << "test_peers_dont_affect_rank passed\n";
}

// ─── Runner ──────────────────────────────────────────────────────────────────

int main(){
    test_single_node();
    test_simple_chain();
    test_multiple_rank_zero_nodes();
    test_diamond();
    test_unequal_paths_to_same_node();
    test_two_disconnected_chains();
    test_peers_dont_affect_rank();

    std::cout << "\nAll flattening tests passed.\n";
    return 0;
}