#pragma once
#include <iostream>
#include <memory>

class DoublyLinkedList {
private:
    struct Node {
        int value;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;

        Node(int value) : value(value), next(nullptr), prev(nullptr) {}
        ~Node(){
            std::cout << "Destroying Node " << value << std::endl;
        }
    };

    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;

public:
    DoublyLinkedList() = default;
    ~DoublyLinkedList() = default;

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    void push_back(int value){
        auto n = std::make_shared<Node>(value);

        if (head_ == nullptr)
            head_ = n;
        else{
            tail_->next = n;
            n->prev = tail_;
        }

        tail_ = n;
    }

    void print_forward(std::ostream& os) const{
        os << '[';

        auto cur = head_;
        while (cur != nullptr){
            os << cur->value;
            if(cur->next != nullptr)
                os << ", ";

            cur = cur->next;
        }
        os << "]\n";
    }
};
