#pragma once
#include <iostream>
using std::cout, std::endl;

class LinkedList{

private:
    struct Node{
        int value;
        Node* next;

        Node(int value) : value(value), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}
    ~LinkedList(){
        Node* cur = head_;

        while(cur != nullptr){
            Node* upcoming = cur->next;
            delete cur;
            cur = upcoming;
        }
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_back(int value){
        Node* n = new Node(value);

        //runs if LinkedList is empty (appending first node)
        if(head_ == nullptr)
            head_ = n;
        //LinkedList is not empty:
        else
            tail_->next = n;
        tail_ = n;
    }

    void print(std::ostream& os) const{
        Node* cur = head_;

        os << "[";
        while (cur != nullptr){
            os << cur->value;
            if (cur->next != nullptr)
                os << ", ";
            cur = cur->next;
        }
        os << "]" << endl;
    }
};
