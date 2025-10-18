//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/27/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator it = remove(nums.begin(), nums.end(), 0);
        for (; it != nums.end(); ++it) {
            *it = 0;
        }
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {0,1,0,3,12};
    Solution solution;
    solution.moveZeroes(nums);
    for (int num:nums) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

