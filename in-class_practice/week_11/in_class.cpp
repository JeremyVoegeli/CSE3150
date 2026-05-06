#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using std::cout, std::endl, std::string, std::vector;

int main(){
    string sentence = "C++ is so much fun";

    std::stringstream ss(sentence);
    string word;
    vector<string> words;

    while(ss >> word){
        words.push_back(word);
    }

    for(auto it = words.rbegin(); it != words.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
