#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "announcement.hpp"

class Policy{
public:
    virtual void process_announcement(const Announcement& a) = 0;
    virtual void add_to_received_queue(const Announcement& a) = 0;
    virtual void clear_received_queue() = 0;
    virtual std::unordered_map<std::string, std::vector<Announcement>>& get_received_queue() = 0;
    virtual std::unordered_map<std::string, Announcement>& get_local_rib() = 0;
    virtual const std::unordered_map<std::string, Announcement>& get_local_rib() const = 0;

    virtual ~Policy() = default;
};

class BGP : public Policy{
public:
    int asn;
    std::unordered_map<std::string, Announcement> local_rib;
    std::unordered_map<std::string, std::vector<Announcement>> received_queue;

    BGP(int ASN) : asn(ASN) {}

    void process_announcement(const Announcement& a) override;
    void add_to_received_queue(const Announcement& a) override;
    void clear_received_queue() override;
    std::unordered_map<std::string, std::vector<Announcement>>& get_received_queue() override{
        return received_queue;
    }
    std::unordered_map<std::string, Announcement>& get_local_rib() override{
        return local_rib;
    }

    const std::unordered_map<std::string, Announcement>& get_local_rib() const override{
        return local_rib;
    }
};

class ROV : public BGP{
public:
    ROV(int asn) : BGP(asn) {}
    void process_announcement(const Announcement& a) override;
};
