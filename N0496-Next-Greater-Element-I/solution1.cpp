//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/12/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mymap;
        stack<int> stk;
        for (int i = nums2.size()-1; i >= 0 ; --i) {
            while(!stk.empty() && nums2[i] >= stk.top()){
                stk.pop();
            }
            mymap[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            res[i] = mymap[nums1[i]];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution solution;
    vector<int> resArray = solution.nextGreaterElement(nums1, nums2);
    for(const auto& num : resArray){
        cout << num << endl;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


