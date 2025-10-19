//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/6/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> map;
        int maxans = INT_MIN;
        int res;
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i]==key){
                map[nums[i+1]]++;
                if (map[nums[i+1]] > maxans){
                    maxans = max(map[nums[i+1]], maxans);
                    res = nums[i+1];
                }
            }
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,100,200,1,100};
    int key = 1;
    Solution solution;
    cout << solution.mostFrequent(nums, key);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


