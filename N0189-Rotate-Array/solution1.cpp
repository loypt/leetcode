//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
    void reverse(vector<int>& nums, int left, int right){
        while(left < right){
            nums[left] ^= nums[right];
            nums[right] ^= nums[left];
            nums[left] ^= nums[right];
            left++;
            right--;
        }
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {-1};
    int k = 2;
    Solution solution;
    solution.rotate(nums, k);
    for (int num: nums) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

