//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/28/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lpos = 0, rpos = nums.size();
        while (lpos < rpos){
            if (nums[lpos] == val){
                nums[lpos] = nums[rpos-1];
                rpos--;
            }else{
                lpos++;
            }
        }
        return lpos;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {3,2,2,3};
    int val = 3;
    Solution solution;
    int res = solution.removeElement(nums, val);
    cout << "res = " << res << endl;
    for (int i = 0; i < res; ++i) {
        cout << nums[i] << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

