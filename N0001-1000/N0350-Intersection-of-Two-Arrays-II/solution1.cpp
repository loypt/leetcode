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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()){
            if (nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                ++i;
                ++j;
            }else if(nums1[i] > nums2[j]){
                ++j;
            }else{
                ++i;
            }
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2, 2};
    Solution solution;
    vector<int> res = solution.intersect(nums1, nums2);
    for (int n:res) {
        cout << n << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

