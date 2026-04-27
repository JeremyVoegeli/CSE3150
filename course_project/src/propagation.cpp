#include "propagation.hpp"

void send_announcement(
    const Announcement& a,
    Graph::AS* sending_as,
    Graph::AS* receiving_as,
    Relationship relationship
){
    Announcement copy = a;
    copy.next_hop_asn = sending_as->asn();
    copy.received_from = relationship;
    receiving_as->policy->add_to_received_queue(copy);
}

void process_received_queue(Graph::AS* node){
    auto& queue = node->policy->get_received_queue();
    for (const auto& [prefix, announcements] : queue){
        for (const Announcement& a : announcements){
            node->policy->process_announcement(a);
        }
    }
    node->policy->clear_received_queue();
}

void propagate(Graph& g, const std::vector<std::vector<int>>& ranks){
    // ── Propagate Up ────────────────────────────────────────────────────────
    // starting at rank 0, send announcements up to providers rank by rank
    for (size_t rank = 0; rank < ranks.size(); rank++){
        // send phase: all ASes at this rank send to their providers
        for (int asn : ranks[rank]){
            Graph::AS* node = g.get(asn);
            const auto& local_rib = node->policy->get_local_rib();
            for (const auto& [prefix, announcement] : local_rib){
                for (int provider_asn : node->providers){
                    Graph::AS* provider_node = g.get(provider_asn);
                    send_announcement(announcement, node, provider_node, Relationship::Customer);
                }
            }
        }

        // process phase: providers of this rank process their received queues
        for (int asn : ranks[rank]){
            for (int provider_asn : g.get(asn)->providers){
                Graph::AS* provider_node = g.get(provider_asn);
                process_received_queue(provider_node);
            }
        }
    }

    // ── Propagate Across ─────────────────────────────────────────────────────
    // all ASes send to peers first, then all process — prevents multi-hop peer routing
    for (const auto& [asn, node] : g.nodes()){
        Graph::AS* sender = g.get(asn);
        const auto& local_rib = sender->policy->get_local_rib();
        for (const auto& [prefix, announcement] : local_rib){
            for (int peer_asn : sender->peers){
                Graph::AS* peer_node = g.get(peer_asn);
                send_announcement(announcement, sender, peer_node, Relationship::Peer);
            }
        }
    }

    // all ASes process their received queues after all sends are complete
    for (const auto& [asn, node] : g.nodes()){
        process_received_queue(g.get(asn));
    }

    // ── Propagate Down ───────────────────────────────────────────────────────
    // starting at the top rank, send announcements down to customers rank by rank
    for (int rank = static_cast<int>(ranks.size()) - 1; rank >= 0; rank--){
        // send phase: all ASes at this rank send to their customers
        for (int asn : ranks[rank]){
            Graph::AS* node = g.get(asn);
            const auto& local_rib = node->policy->get_local_rib();
            for (const auto& [prefix, announcement] : local_rib){
                for (int customer_asn : node->customers){
                    Graph::AS* customer_node = g.get(customer_asn);
                    send_announcement(announcement, node, customer_node, Relationship::Provider);
                }
            }
        }

        // process phase: customers of this rank process their received queues
        for (int asn : ranks[rank]){
            for (int customer_asn : g.get(asn)->customers){
                Graph::AS* customer_node = g.get(customer_asn);
                process_received_queue(customer_node);
            }
        }
    }
}
