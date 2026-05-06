#include <iostream>
#include <string>
#include <memory>
using std::cout, std::endl, std::string;

struct Book {
    string title;
    string author;
    int pages;
    void printBook() const;
};

void Book::printBook() const{
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Number of pages: " << pages << endl;
}

int main(){
    std::unique_ptr<Book> book1 = std::make_unique<Book>();
    book1 -> title = "Dick Eating 101.";
    book1 -> author = "Poop Name";
    book1 -> pages = 670;

    book1 -> printBook();

    std::unique_ptr<Book> book2 = std::move(book1);
    cout << "\nMoving ownership...\n" << endl;

    if (book1 == nullptr){
        cout << "book1 is empty.\n" << endl;
    }

    book2 -> printBook();

    return 0;
}
