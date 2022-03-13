//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/12/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2){
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum  = *max_element(nums.begin(), nums.end());
        // if odd
        if (sum & 1){
            return false;
        }
        int target = sum/2;
        if (maxNum > target){
            return false;
        }
        vector<int> dp(target+1, 0);
        dp[0] = true;
        for (int i = 1; i < n; ++i) {
            int num  = nums[i];
            for (int j = target; j >= num; --j) {
                dp[j] |= dp[j-num];
            }
        }
        return dp[target];
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums= {1,5,11,5};
    Solution solution;
    cout << solution.canPartition(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


