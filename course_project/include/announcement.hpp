#pragma once
#include <string>
#include <vector>

enum class Relationship{
    Origin,
    Customer,
    Peer,
    Provider
};

struct Announcement{
    std::string prefix;
    std::vector<int> as_path;
    int next_hop_asn;
    Relationship received_from;

    //constructors
    Announcement() :
        prefix(""),
        next_hop_asn(-1),
        received_from(Relationship::Origin) {}

    Announcement(const std::string& p) :
        prefix(p),
        next_hop_asn(-1),
        received_from(Relationship::Origin) {}
};
