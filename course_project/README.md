# BGP Simulator
**Author:** Jeremy Voegeli  
**Course:** CSE3150

## Overview
A C++ simulator for BGP (Border Gateway Protocol) routing. The simulator builds an AS (Autonomous System) graph from CAIDA topology data, propagates announcements through the graph using standard BGP policies, and outputs the resulting routing tables to a CSV file.

## Compilation
```bash
c++ src/*.cpp -std=c++23 -I include -o program.out
```

## Usage
```bash
./program.out <graph_file> <announcements_file> <rov_file>
```

- `graph_file` - CAIDA AS relationship file (pipe-delimited, e.g. `20260301.as-rel2.txt`)
- `announcements_file` - CSV file with columns `asn`, `prefix`, `rov_invalid`
- `rov_file` - text file with one ASN per line representing ASes that deploy ROV

## Output
The program writes `ribs.csv` to the current directory with columns:
- `asn` - the Autonomous System Number
- `prefix` - the IP prefix (IPv4 or IPv6)
- `as_path` - the AS path to reach the prefix, formatted as `ASN1-ASN2-ASN3`

## Error Codes
- `0` - success
- `1` - file error (could not open one of the input files)
- `2` - cycle detected in the provider/customer relationships

If a cycle is detected, the program prints the cycle to stdout before exiting:
```
Cycle detected: 1 -> 2 -> 3 -> 1
```

## Project Structure
```
include/
    announcement.hpp: Announcement struct and Relationship enum
    cycle_detection.hpp: DFS-based cycle detection
    flattening.hpp: BFS-based graph flattening
    graph.hpp: Graph and AS node definitions
    output.hpp: CSV output
    policy.hpp: Policy, BGP, and ROV classes
    propagation.hpp: Announcement propagation
    read_data.hpp: Input file parsing
src/
    cycle_detection.cpp
    flattening.cpp
    main.cpp
    output.cpp
    policy.cpp
    propagation.cpp
    read_data.cpp
```

## Design Decisions

### Graph Representation
The AS graph is stored as an `unordered_map<int, AS>` keyed by ASN. Each AS node stores its providers, customers, and peers as `unordered_set<int>` to provide O(1) duplicate detection and O(1) lookup. This is important for a dataset with about 100k nodes and about 500k edges.

### Cycle Detection
Cycle detection uses a DFS with three-color marking (Unvisited, Visiting, Done). Only provider edges are traversed since a provider cycle and customer cycle are the same cycle viewed from opposite directions. Visit state is kept in a local `unordered_map` rather than stored on each node, allowing multiple DFS passes without resetting state.

### Graph Flattening
The graph is flattened using BFS starting from all rank-0 nodes. Each AS is assigned a propagation rank equal to the longest path from any leaf node to that AS. This ensures correct propagation ordering even when a node is reachable via multiple paths of different lengths.

### Policy System
Each AS holds a `unique_ptr<Policy>` which defaults to `BGP`. The `Policy` abstract base class defines the interface for processing and storing announcements. `ROV` inherits from `BGP` and overrides `process_announcement` to drop announcements marked as ROV invalid before passing valid ones to the BGP logic.

### Announcement Propagation
Propagation follows the standard BGP valley-free routing model in three phases:
1. **Up:** announcements travel from customers to providers, rank by rank
2. **Across:** all ASes send to peers simultaneously, then all process (prevents multi-hop peer routing)
3. **Down:** announcements travel from providers to customers, rank by rank

Each AS prepends its own ASN to the AS path when storing an announcement. Conflict resolution prefers: better relationship > shorter AS path > lower next hop ASN.