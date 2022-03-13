//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/13/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftIndex = binarySearch(nums, target, true);
        int rightIndex = binarySearch(nums, target, false) - 1;
        if (leftIndex <= rightIndex && rightIndex < nums.size() && nums[rightIndex] == target && nums[leftIndex] == target){
            return rightIndex-leftIndex+1;
        }
        return 0;
    }

    int binarySearch(vector<int>& nums, int target, bool lower){
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)){
                right = mid - 1;
                ans = mid;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Solution solution;
    cout << solution.search(nums, target);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

