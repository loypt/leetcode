//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/27/22.
//

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> string_list;
        string s = "";
        int i = 0;
        while(i < nums.size()) {
            int begin_pos = i;
            i++;
            while (i < nums.size() && nums[i-1]+1 == nums[i]){
                i++;
            }
            int end_pos = i - 1;
            s += to_string(nums[begin_pos]);
            if (end_pos > begin_pos){
                s += "->";
                s += to_string(nums[end_pos]);
            }
            string_list.push_back(s);
            s = "";
        }
        return string_list;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {0,1,2,4,5,7};
    Solution solution;
    vector<string> res = solution.summaryRanges(nums);
    for (string s : res) {
        cout << s << endl;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

