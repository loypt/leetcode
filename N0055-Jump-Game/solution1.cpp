//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/12/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (i > maxPos){
                return false;
            }
            maxPos = max(i+nums[i], maxPos);
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int>  nums = {2,3,1,1,4};
    Solution solution;
    cout << solution.canJump(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


