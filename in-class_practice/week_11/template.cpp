#include <iostream>
#include <memory>

template <class T>
std::ostream& operator << (std::ostream& os, const std::shared_ptr<T>& p){
    return os << p.get() << '[' << p.use_count() << ']';
}

template <class T>
std::ostream& operator << (std::ostream& os, std::weak_ptr<T>& p){
    T* raw = nullptr;
    {
        auto sp = p.lock();
        raw = sp.get();
    }
    return os << raw << '[' << p.use_count() << ']';
}
