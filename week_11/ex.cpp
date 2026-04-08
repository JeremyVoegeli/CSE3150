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

struct Foo {
    int a;
    Foo(int x) {a = x;}
    ~Foo() { //destructor, runs when struct goes out of scope
        std::cout << "Foo(" << this << ") is destructed" << std::endl;
    }
    void printMe() {
        std::cout << "printing " << this << " is " << a << std::endl;
    }
};

void fun(std::weak_ptr<Foo> p){
    std::cout << "p in fun=" << p << std::endl;
    auto up = p.lock();
    std::cout << "up in fun" << up << std::endl;
    up->printMe();
}

void test(){
    std::shared_ptr<Foo> p = std::make_shared<Foo>(42);
    std::weak_ptr<Foo> q(p);
    fun(q);
    std::cout << "Before q.reset()" << q << std::endl;
    q.reset();
    std::cout << "After q.reset()" << q << std::endl;
    p.reset();
    std::cout << "After p.reset()" << p << std::endl;
}

int main(){
    test();
    return 0;
}
