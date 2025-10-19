//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/6/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = unique(nums.begin(), nums.end()) - nums.begin();
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= k){
                res += nums[i];
                ++k;
            }
        }
        return (1LL + k)*k/2-res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,4,25,10,25};
    int k = 2;
    Solution solution;
    cout << solution.minimalKSum(nums, k);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

