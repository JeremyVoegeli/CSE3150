#include <iostream>
#include <memory>
#include <string>
using std::cout, std::endl, std::string;

struct Book {
    string title;
    int pages;
};

int main(){
    std::unique_ptr<Book> b1 = std::make_unique<Book>();;

    b1->title = "How to Cook.";
    b1->pages = 67;

    cout << "Book title: " << b1->title << endl;
    cout << "Number of pages: " << b1->pages << endl;

    std::unique_ptr<Book> b2;
    b2 = std::move(b1);

    cout << "B1 is Null? " << (b1 == nullptr) << endl;
    cout << "Book title: " << b2->title << endl;
    cout << "Number of pages: " << b2->pages << endl;
    return 0;
}
