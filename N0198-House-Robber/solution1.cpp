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

class Solution{
public:
    int rob(vector<int>& nums){
        int size = nums.size();
        if (size == 0){
            return 0;
        }
        if (size == 1){
            return nums[0];
        }
        vector<int> state(size, 0);
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
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
    vector<int> nums = {1, 2, 3, 1};
    Solution solution;
    cout << solution.rob(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

