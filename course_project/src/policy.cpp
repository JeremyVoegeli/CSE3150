#include "policy.hpp"

void BGP::process_announcement(const Announcement& a){
    Announcement copy = a;
    copy.as_path.insert(copy.as_path.begin(), asn);

    if (!local_rib.contains(copy.prefix)){
        local_rib[copy.prefix] = copy;
    } else {
        const Announcement& old = local_rib[copy.prefix];

        if (copy.received_from < old.received_from){
            local_rib[copy.prefix] = copy;
        } else if (
            copy.received_from == old.received_from
            && copy.as_path.size() < old.as_path.size()
        ){
            local_rib[copy.prefix] = copy;
        } else if (
            copy.received_from == old.received_from
            && copy.as_path.size() == old.as_path.size()
            && copy.next_hop_asn < old.next_hop_asn
        ){
            local_rib[copy.prefix] = copy;
        }
    }
};

void BGP::add_to_received_queue(const Announcement& a){
    std::vector<Announcement>& queue_vector = received_queue[a.prefix];
    queue_vector.push_back(a);
}

void BGP::clear_received_queue(){
    received_queue.clear();
}

void ROV::process_announcement(const Announcement& a){
    if(!a.rov_invalid){
        BGP::process_announcement(a);
    }
};
