#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

void star_frame(string& message){
    size_t width = message.size() + 4;

    for (int i = 0; i < width; i++){
        cout << "*";
    }
    cout << endl;

    cout << "* " << message << " *" << endl;

    for (int i = 0; i < width; i++){
        cout << "*";
    }
    cout << endl;
}

int main(){
    string m = "Hello World";
    star_frame(m);
    return 0;
}
