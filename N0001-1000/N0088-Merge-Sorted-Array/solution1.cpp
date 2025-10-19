//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <math.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m+n-1;
        m--;
        n--;
        while (n >= 0) {
            nums1[pos--] = (m >= 0 && nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
        }
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    Solution solution;
    solution.merge(nums1, m, nums2, n);
    for (int num : nums1) {
        cout << num << " ";
    }
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

