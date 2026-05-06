#include <iostream>
#include <memory>
using std::cout, std::endl;

struct Foo{
    int x;
    Foo(int v) {x = v;}
    ~Foo() {
        cout << "Foo(" << x << ") is deconstructed." << endl;
    }
};

void share(const std::shared_ptr<Foo>& p){
    cout << "Use count: " << p.use_count() << endl;
}

int main(){
    std::shared_ptr fpq = std::make_shared<Foo>(42);
    share(fpq);
    return 0;
}
