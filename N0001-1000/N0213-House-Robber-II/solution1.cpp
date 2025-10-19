//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/11/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1){
            return nums[0];
        }else if(len == 2){
            return max(nums[0], nums[1]);
        }
        return  max(robRange(nums, 0, len - 2), robRange(nums, 1, len-1));

    }

    int robRange(vector<int>& nums, int start, int end){
        int first = nums[start], second = max(nums[start], nums[start+1]);
        for (int i = start + 2; i <= end; ++i) {
            int temp = second;
            second = max(first+nums[i], second);
            first = temp;
        }
        return second;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,2,3,1};
    Solution solution;
    cout << solution.rob(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


