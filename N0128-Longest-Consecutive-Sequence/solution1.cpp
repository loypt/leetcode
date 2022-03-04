//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/4/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // using set remove repeat value
        unordered_set<int> numsSet;
        for (const int& num:nums) {
            numsSet.insert(num);
        }

        int longestSerial = 0;
        for (const int& num: nums) {
            if (!numsSet.count(num-1)){
                int curNum = num;
                int curSerial = 1;

                while (numsSet.count(curNum+1)){
                    curNum += 1;
                    curSerial += 1;
                }

                longestSerial = max(longestSerial, curSerial);
            }
        }

        return longestSerial;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {100,4,200,1,3,2};
    Solution solution;
    cout << solution.longestConsecutive(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

