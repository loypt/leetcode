//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/9/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution{
public:
    vector<int> sortedSquares(vector<int>& nums){
        int len = nums.size();
        vector<int> ans(len);
        for (int i = 0, j = len -1, pos = len - 1; i <= j;) {
            if (nums[i]*nums[i] > nums[j]*nums[j]){
                ans[pos] = nums[i]*nums[i];
                ++i;
            }else{
                ans[pos]  = nums[j]*nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {-4,-1,0,3,10};
    Solution solution;
    vector<int> resarray = solution.sortedSquares(nums);
    for(const auto& num : resarray){
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


