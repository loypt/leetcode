//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/3/22.
//

#include <iostream>
#include <chrono>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4){
        unordered_map<int, int> countFG;
        int res = 0;
        for (int num1:nums1) {
            for (int num2:nums2) {
                countFG[num1+num2]++;
            }
        }
        for (int num3:nums3) {
            for (int num4:nums4) {
                if (countFG.count(-(num3+num4))){
                    res += countFG[-(num3+num4)];
                }
            }
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    Solution solution;
    cout << solution.fourSumCount(nums1, nums2, nums3, nums4);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

