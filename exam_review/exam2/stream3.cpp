#include <iostream>
#include <sstream>
#include <vector>
using std::cin, std::cout, std::endl, std::string, std::vector, std::getline, std::istringstream;

int main(){
    string line;
    cout << "Enter input line (words separated by commas)" << endl;
    getline(cin, line);
    istringstream ss(line);

    vector<string> words;
    string word;
    while (getline(ss, word, ',')){
        words.push_back(word);
    }

    string longest = words[0];
    cout << endl << "Words entered:" << endl;
    for(string w : words){
        cout << w << endl;
        if (w.size() > longest.size()){longest = w;}
    }

    cout << endl << "Number of words entered: " << words.size() << endl;
    cout << "Longest word: " << longest << endl;
    return 0;
}
