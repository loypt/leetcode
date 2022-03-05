//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/4/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        int bucket[5001] = {0};
        for (int num:nums) {
            bucket[num]++;
        }
        int big, small;
        if (len&1){
            big = len-2;
            small = len-1;
        }else{
            big = len-1;
            small = len-2;
        }
        int j = 5000;
        // insert big
        for (int i = 1; i <= big; i+=2) {
            while (bucket[j] == 0) j--;
            nums[i]=j;
            bucket[j]--;
        }
        // insert small
        for (int i = 0; i <= small; i+=2) {
            while (bucket[j]==0)j--;
            nums[i]=j;
            bucket[j]--;
        }
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,5,1,1,6,4};
    Solution solution;
    solution.wiggleSort(nums);
    for (int num:nums) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

