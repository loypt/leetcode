//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/9/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x){
            return -1;
        }
        int left = 0, right = 0, total = 0;
        int ans = INT_MAX;
        while (left < len){
            total += nums[left];
            while (sum - total < x){
                total -= nums[right];
                right++;
            }
            if (sum-total==x){
                ans = min(ans, len-(left-right+1));
            }
            left++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,1,4,2,3};
    int x = 5;
    Solution solution;
    cout << solution.minOperations(nums, x);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


