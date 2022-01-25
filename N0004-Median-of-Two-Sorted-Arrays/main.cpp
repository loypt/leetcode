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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto i = nums1.size();
        auto j = nums2.size();
        vector<int> res_list = {};
        while (i && j) {
            if (nums1[nums1.size()-i] <= nums2[nums2.size()-j]) {
                res_list.push_back(nums1[nums1.size()-i]);
                i--;
            }else{
                res_list.push_back(nums2[nums2.size()-j]);
                j--;
            }
        }
        while(i){
            res_list.push_back(nums1[nums1.size()-i]);
            i--;
        }
        while(j){
            res_list.push_back(nums2[nums2.size()-j]);
            j--;
        }
        if (res_list.size() % 2 == 0) {
            cout << "true" << endl;
            return (double)(res_list[res_list.size()/2 -1] + res_list[res_list.size()/2]) / 2;
        }else{
            return res_list[res_list.size()/2];
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> num1 = {1, 2};
    vector<int> num2 = {3, 4};
    Solution solution;
    cout << solution.findMedianSortedArrays(num1, num2);
    
    return 0;
}

