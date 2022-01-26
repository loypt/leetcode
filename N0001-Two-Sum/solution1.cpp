//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int> {i, j};
                }
            }
        }
        return vector<int>{};
    }
};

int main(int argc, const char * argv[]) {
    vector<int> list_temp = {2,7,11,15};
    vector<int> res;
    Solution solution;
    res = solution.twoSum(list_temp, 9);
    cout << "res = { ";
    for (int n : res) {
        cout << n << " " ;
    }
    cout << "}; \n";
    return 0;
}

