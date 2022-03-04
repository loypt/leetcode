//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/4/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long res = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int maxi = nums[i], mini = nums[i];
            for (int j = i+1; j < len; ++j) {
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                res += (maxi-mini);
            }
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {4,-2,-3,4,1};
    Solution solution;
    cout << solution.subArrayRanges(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

