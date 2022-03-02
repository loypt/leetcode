//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/1/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int len = nums.size();
        priority_queue<pair<int, int>> que;
        for (int i = 0; i < k; ++i) {
            que.emplace(nums[i], i);
        }
        vector<int> res_array = {que.top().first};
        for (int i = k; i < len; ++i) {
            que.emplace(nums[i], i);
            while (que.top().second <= i-k){
                que.pop();
            }
            res_array.push_back(que.top().first);
        }
        return res_array;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution solution;
    vector<int>  res = solution.maxSlidingWindow(nums, k);
    for (int num:res) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

