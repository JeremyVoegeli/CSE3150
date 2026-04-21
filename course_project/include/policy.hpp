#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "announcement.hpp"

class Policy{
public:
    virtual void process_announcement(const Announcement& a) = 0;

    virtual ~Policy() = default;
};

class BGP : public Policy{
public:
    std::unordered_map<std::string, Announcement> local_rib;
    std::unordered_map<std::string, std::vector<Announcement>> received_queue;

    void process_announcement(const Announcement& a) override;
    void add_to_received_queue(const Announcement& a);
    void clear_received_queue();
};

class ROV : public BGP{
public:
    void process_announcement(const Announcement& a) override;
};
