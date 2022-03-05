//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/5/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        int res = INT_MIN;
        vector<int> dp(size);
        for (int i = 0; i < size; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution solution;
    cout << solution.lengthOfLIS(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

