#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Graph{
public:
    //each Autonomous System is a node within the graph
    struct AS{
    private:
        int asn_;

    public:
        std::unordered_set<int> providers;
        std::unordered_set<int> customers;
        std::unordered_set<int> peers;
        int rank;

        //constructors
        AS(int asn) : asn_(asn), rank(-1) {}
        AS() : asn_(-1), rank(-1) {}

        //getter for ASN
        int asn() const{
            return asn_;
        }
    };

    //constructors
    Graph() = default;
    ~Graph() = default;

    //getter for map of nodes
    const std::unordered_map<int, AS>& nodes() const{
        return nodes_;
    }

    //getter for node with given ASN
    //returns the pointer to the node or nullptr if node doesn't exist
    AS* get(int asn){
        auto it = nodes_.find(asn);
        if (it != nodes_.end()){
            return &(it->second);
        } else {
            return nullptr;
        }
    }

    //Overloaded const version ^^^
    const AS* get(int asn) const{
        auto it = nodes_.find(asn);
        if (it != nodes_.end()){
            return &(it->second);
        } else {
            return nullptr;
        }
    }

    //create new node with given ASN
    AS& create(int asn){
        auto [it, _] = nodes_.try_emplace(asn, AS(asn));
        return it->second;
    }

    //returns true if ASN is in the graph
    bool contains(int asn) const{
        return nodes_.find(asn) != nodes_.end();
    }

    //creates provider-customer relationship edge in graph
    void add_provider_customer(int provider, int customer){
        AS& p = create(provider);
        AS& c = create(customer);

        p.customers.insert(customer);
        c.providers.insert(provider);
    }

    //creates peer-peer relationship edge in graph
    void add_peer(int peer1, int peer2){
        AS& p1 = create(peer1);
        AS& p2 = create(peer2);

        p1.peers.insert(peer2);
        p2.peers.insert(peer1);
    }

    //prints every ASN in the graph
    void print(std::ostream& os) const{
        for(auto it = nodes_.begin(); it != nodes_.end(); it++){
            os << "ASN: " << it->first << std::endl;
        }
    }
private:
    std::unordered_map<int, AS> nodes_;
};
