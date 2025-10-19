//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/4/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1){
            return 0;
        }
        int res = 0;
        while (res+1<len && nums[res] < nums[res+1]){
            res+=1;
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1, 2, 3, 1};
    Solution solution;
    cout << solution.findPeakElement(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

