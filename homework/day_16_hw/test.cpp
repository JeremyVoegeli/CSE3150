#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> compress_row(const vector<int>& row){
    vector<int> compressed;
    copy_if(row.begin(), row.end(), back_inserter(compressed), [](int x) {return x != 0;});

    while (compressed.size() < 4){
        compressed.push_back(0);
    }

    return compressed;
}

vector<int> merge_row(vector<int> row){
    for(int i = 0; i < 3; i++){
        if(row[i] != 0 && row[i] == row[i + 1]){
            row[i] *= 2;
            row[i + 1] = 0;
        }
    }
    return compress_row(row);
}

int main(){
    vector<int> row1{4, 4, 2, 2};
    vector<int> row2{0, 0, 0, 2};
    vector<int> row3{2, 0, 0, 0};
    vector<int> row4{0, 0, 0, 0};

    vector<vector<int>> board{row1, row2, row3, row4};

    vector<int> merged_row1 = merge_row(row1);
    for (int x : merged_row1){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
