//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/28/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row_nums(rowIndex+1); // Init must have size
        row_nums[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            row_nums[i] = 1LL *row_nums[i-1] * (rowIndex-i+1)/i;
        }
        return row_nums;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int rowIndex = 3;
    Solution solution;
    vector<int> ret = solution.getRow(rowIndex);
    for (int num: ret) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

