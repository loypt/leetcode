//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/13/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution{
public:
    void setZeroes(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; ++i) {
            if (!matrix[i][0]){
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (!matrix[0][j]){
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
        }

        if (flag_col0){
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }

        if (flag_row0){
            for (int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<vector<int>> matrix = {
            {1,1,1},
            {1,0,1},
            {1,1,1}
    };
    Solution solution;
    solution.setZeroes(matrix);
    for (const auto& row:matrix) {
        for(const auto& num : row){
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

