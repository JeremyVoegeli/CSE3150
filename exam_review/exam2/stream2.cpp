#include <iostream>
#include <sstream>
#include <vector>
using std::cin, std::cout, std::endl, std::getline, std::vector, std::string, std::istringstream;

int main(){
    string line;
    cout << "Enter line of User Score pairs:" << endl;
    getline(cin, line);
    cout << endl;

    istringstream ss(line);
    vector<string> names;
    vector<int> scores;
    string name;
    int score;

    while(ss >> name >> score){
        names.push_back(name);
        scores.push_back(score);
    }

    int highest_idx = 0;
    for(int i = 0; i < names.size(); i++){
        cout << names[i] << " scored " << scores[i] << endl;
        if (scores[i] > scores[highest_idx]){highest_idx = i;}
    }
    cout << endl;

    cout << names[highest_idx] << " got the highest score of " << scores[highest_idx] << endl;
    return 0;
}
