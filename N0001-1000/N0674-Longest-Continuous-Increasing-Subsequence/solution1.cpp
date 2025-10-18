//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/8/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        int i = 0;
        int j = 0;
        while (j < len){
            if (j > 0 && nums[j-1] >= nums[j]){
                i = j;
            }
            j++;
            res = max(res, j-i);
        }
        return res;
    }
};



int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,3,5,4,7};
    Solution solution;
    cout << solution.findLengthOfLCIS(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


