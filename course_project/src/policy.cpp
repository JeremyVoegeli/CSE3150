#include "policy.hpp"

void process_announcement(const Announcement& a){
    if (!local_rib.contains(a.prefix)){
        local_rib[a.prefix] = a;
    } else {
        const Announcement& old = local_rib[a.prefix];

        if (a.received_from < old.received_from){
            local_rib[a.prefix] = a;
        } else if (
            a.received_from == old.received_from
            && a.as_path.size() < old.as_path.size()
        ){
            local_rib[a.prefix] = a;
        } else if (
            a.received_from == old.received_from
            && a.as_path.size() < old.as_path.size()
            && a.next_hop_asn < old.next_hop_asn
        ){
            local_rib[a.prefix] = a;
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
