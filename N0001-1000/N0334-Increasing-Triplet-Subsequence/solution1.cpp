//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/27/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) {
            return false;
        }
        int first_num = nums[0], second = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (num > second){
                return true;
            } else if (num > first_num){
                second = num;
            }else {
                first_num = num;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,2,3,4,5};
    Solution solution;
    cout << solution.increasingTriplet(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

