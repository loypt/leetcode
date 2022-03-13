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
    bool searchMatrix(vector<vector<int>>& matrix , int target){
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> &a){
            return b < a[0];
        });
        if (row == matrix.begin()){
            return false;
        }
        --row;
        return binary_search(row->begin(), row->end(), target);
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<vector<int>> matrix = {
            {1,3,5,7},
            {10,11,16,20},
            {23,30,34,60}
    };
    int target = 3;
    Solution solution;
    cout << solution.searchMatrix(matrix, target);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

