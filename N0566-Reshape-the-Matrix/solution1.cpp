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
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int orr = mat.size();
        int orc = mat[0].size();
        if (orr*orc != r*c){
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        for (int x = 0; x <  orr* orc; ++x) {
            ans[x/c][x%c] = mat[x/orc][x%orc];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    int r = 1, c = 4;
    Solution solution;
    vector<vector<int>> resArray = solution.matrixReshape(mat, r, c);
    for(const auto& array: resArray){
        for(const auto& num: array){
            cout<< num << " ";
        }
        cout<< endl;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


