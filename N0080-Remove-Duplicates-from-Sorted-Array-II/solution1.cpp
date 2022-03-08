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
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 2){
            return len;
        }
        int j=2;
        for (int i = 2; i < len; ++i) {
            if (nums[i] != nums[j-2]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};



int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,1,1,2,2,3};
    Solution solution;
    int len = solution.removeDuplicates(nums);
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << endl;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


