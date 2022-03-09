//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/9/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };
    Status pushUp(Status l, Status r){
        int iSum = l.iSum+r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum+r.lSum);
        return (Status){lSum, rSum, mSum, iSum};
    };
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size()-1).mSum;
    }

    Status get(vector<int>& a, int l, int r){
        if (l == r){
            return (Status){a[l], a[l], a[l], a[l]};
        }
        int m = (l+r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m+1, r);
        return pushUp(lSub, rSub);
    }

};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    cout << solution.maxSubArray(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


