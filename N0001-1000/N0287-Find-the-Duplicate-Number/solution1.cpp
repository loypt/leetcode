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
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int lpos = 1, rpos = len-1, res = -1;
        while (lpos <= rpos){
            int mid = (lpos+rpos)/2;
            int cnt = 0;
            for (int i = 0; i < len; ++i) {
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid){
                lpos = mid+1;
            }else{
                rpos = mid-1;
                res = mid;
            }
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1, 3, 4, 2, 2};
    Solution solution;
    cout << solution.findDuplicate(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

