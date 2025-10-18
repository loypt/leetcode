//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <array>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxArr(nums), minArr(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxArr[i] = max(maxArr[i-1]*nums[i], max(nums[i], minArr[i-1]*nums[i])); // positive and negative
            minArr[i] = min(minArr[i-1]*nums[i], min(nums[i], maxArr[i-1]*nums[i]));
        }
        return *max_element(maxArr.begin(), maxArr.end());

    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {2,3,-2,4};
    Solution solution;
    cout << solution.maxProduct(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

