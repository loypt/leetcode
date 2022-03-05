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
private:
    int rob(vector<int> &nums){
        int size = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
            int temp = second;
            second = max(first+nums[i], second);
            first = temp;
        }
        return second;
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 0;
        for (int num : nums) {
            maxNum = max(maxNum, num);
        }
        vector<int> sum(maxNum+1);
        for (int num : nums) {
            sum[num] +=  num;
        }
        return rob(sum);
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {3,4,2};
    Solution solution;
    cout << solution.deleteAndEarn(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

