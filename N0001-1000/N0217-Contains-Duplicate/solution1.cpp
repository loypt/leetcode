//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/27/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set_res;
        for (int num:nums) {
            if (!set_res.insert(num).second){
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,2,3,4};
    Solution solution;
    cout << solution.containsDuplicate(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

