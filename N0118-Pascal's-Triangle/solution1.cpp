//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/12/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i+1);
            ret[i][0] = ret[i][i] = 1;
            for(int j = 1; j < i; j++){
                ret[i][j] = ret[i-1][j]+ret[i-1][j-1];
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int numRows = 5;
    Solution solution;
    vector<vector<int>> res = solution.generate(numRows);
    for (const auto& array:res) {
        for (const auto& num:array) {
            cout << num << " ";
        }
        cout << endl;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


