#pragma once
#include <iostream>
#include <memory>

class LinkedList{
private:
    struct Node{
        int value;
        std::unique_ptr<Node> next;

        Node(int value) : value(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head_;
    Node* tail_;

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}
    ~LinkedList() = default;

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_back(int value){
        std::unique_ptr n = std::make_unique<Node>(value);
        Node* raw = n.get();

        //if LinkedList is empty
        if (head_ == nullptr)
            head_ = std::move(n);
        //if LinkedList isn't empty
        else
            tail_->next = std::move(n);

        tail_ = raw;
    }

    void print(std::ostream& os) const{
        os << "[";
        Node* cur = head_.get();

        while (cur != nullptr){
            os << cur->value;
            if (cur->next != nullptr)
                os << ", ";
            cur = cur->next.get();
        }
        os << "]" << std::endl;
    }
};
