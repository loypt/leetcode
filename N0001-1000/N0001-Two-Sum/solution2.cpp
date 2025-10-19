//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/10/22.
//

#include <iostream>
#include <chrono>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = ht.find(target-nums[i]);
            if (it != ht.end()){
                return {it->second, i};
            }
            ht[nums[i]] = i;
        }
        return {};
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution solution;
    vector<int> resArray = solution.twoSum(nums, target);
    for (const auto& num:resArray) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


