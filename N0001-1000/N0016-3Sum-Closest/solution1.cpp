//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int lens = nums.size();
        int best = 999999;
        
        // update answer according to abs of difference
        auto update = [&](int cur) {
            if (abs(cur-target) < abs(best - target)) {
                best = cur;
            }
        };
        
        // Enum a
        for (int i = 0; i < lens; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            // Double pointer enumerate b and c
            int j = i + 1, k = lens -1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                }
                update(sum);
                if (sum > target) {
                    // If sum bigger than target, then move c(k) pointer
                    int k0 = k - 1;
                    while (j < k0 && nums[k0] == nums[k]) {
                        --k0;
                    }
                    k = k0;
                } else {
                    // If sum less than target, then move b(j) pointer
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j]) {
                        ++j0;
                    }
                    j = j0;
                }
            }
        }
        return best;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    vector<int> arrays = {-1,2,1,-4};
    int target = 1;
    Solution solution;
    cout << solution.threeSumClosest(arrays, target);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

