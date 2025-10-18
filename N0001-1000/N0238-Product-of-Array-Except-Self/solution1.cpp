//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/28/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int lpos = 1, rpos = 1;
        vector<int> ret_array(len, 1);
        for (int i = 1; i < len; ++i) {
            lpos *= nums[i-1];
            rpos *= nums[len-i];
            ret_array[i] *= lpos;
            ret_array[len-1-i] *= rpos;
        }
        return ret_array;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,2,3,4};
    Solution solution;
    vector<int> res = solution.productExceptSelf(nums);
    for (int s : res) {
        cout << s << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

