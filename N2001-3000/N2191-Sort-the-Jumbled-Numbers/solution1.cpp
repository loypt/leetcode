//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/6/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<vector<int>> mappedNums;
        for (int i = 0; i < nums.size(); ++i) {
            int mapVal = getMapVal(mapping, nums[i]);
            mappedNums.push_back({mapVal, i});
        }
        sort(mappedNums.begin(), mappedNums.end());
        vector<int> res;
        for (const auto& num:mappedNums) {
            res.push_back(nums[num[1]]);
        }
        return res;
    }

    int getMapVal(vector<int>& mapping, int num){
        string s = to_string(num);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ans = ans * 10 + mapping[s[i]-'0'];
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> mapping = {8,9,4,0,2,1,3,5,7,6};
    vector<int> nums = {991,338,38};
    Solution solution;
    vector<int> resArray = solution.sortJumbled(mapping, nums);
    for (const auto& num: resArray) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

