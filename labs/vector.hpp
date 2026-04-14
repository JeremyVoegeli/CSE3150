#pragma once
#include <cstddef> // for size_t
#include <stdexcept>
#include <concepts>

template <typename T>
concept EqualityComparable = requires(const T& a, const T& b){
    {a == b} -> std::convertible_to<bool>;
};

template <EqualityComparable T>
class Vector {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void resize_capacity(size_t new_capacity){
        T* new_data = static_cast<T*>(::operator new(sizeof(T) * new_capacity));

        for (int i = 0; i < size_; i++){
            new_data[i] = data_[i];
        }

        ::operator delete(data_);

        data_ = new_data;
        capacity_ = new_capacity;
}

public:
    class Iterator {
    private:
        T* current_;
    public:
        Iterator(T* ptr) : current_(ptr) {}
        T& operator*() {
            return *current_;
        }

        Iterator& operator++() {
            ++current_;
            return *this;
        }

        bool operator!=(const Iterator& other) const{
            return (current_ != other.current_);
        }
    };

    class ConstIterator {
     private:
        const T* current_;
    public:
        ConstIterator(const T* ptr) : current_(ptr) {}

        const T& operator*() const{
            return *current_;
        }

        ConstIterator& operator++(){
            ++current_;
            return *this;
        }
        bool operator!=(const ConstIterator& other) const{
            return (current_ != other.current_);
        }
    };

    Vector(){
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    ~Vector(){
        ::operator delete(data_);
    }

    Vector(const Vector&) = delete;
    Vector& operator=(const Vector&) = delete;

    T& operator[](size_t index){
    return data_[index];
    }

    const T& operator[](size_t index) const{
    return data_[index];
    }

    bool operator==(const Vector<T>& other) const{
    if(size_ != other.size()){
        return false;
    }

    for (int i = 0; i < size_; i++){
        if (data_[i] != other[i]){
            return false;
        }
    }
    return true;
}

    size_t size() const{
        return size_;
    }
    size_t capacity() const{
        return capacity_;
    }
    bool empty() const{
        return (size_ == 0);
    }

    void push_back(const T& value){
    if (size_ == capacity_){
        if(capacity_ == 0){
            resize_capacity(1);
        } else {
            resize_capacity(capacity_ * 2);
        }
    }
    data_[size_] = value;
    size_++;
}

    T& at(size_t index){
    if(index >= size_){
        throw std::out_of_range("Index out of range.");
    }
    return data_[index];
}

    Iterator begin(){
        return data_;
    }
    Iterator end(){
        return (data_ + size_);
    }

    ConstIterator begin() const{
        return data_;
    }
    ConstIterator end() const{
        return (data_ + size_);
    }
};
