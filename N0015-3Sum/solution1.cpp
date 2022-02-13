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
#include <unordered_map>
#include <math.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int lens = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res_array;
        
        // enum a
        for (int i = 0; i < lens; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue; // Different from the last enumeration
            }
            
            // c point
            int k = lens-1;
            int target = -nums[i];
            
            // enum b
            for (int j = i+1; j < lens; ++j) {
                if (j != i + 1 && nums[j] == nums[j-1]) {
                    continue; // Different from the last enumeration
                }
                // Insure pointer b is left in pointer c
                while (j<k && nums[j] + nums[k] > target) {
                    --k;
                }
                if (j == k) {
                    break;
                }
                if (nums[j] + nums[k] == target) {
                    res_array.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return res_array;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    vector<int> arrays = {-1,0,1,2,-1,-4};
    Solution solution;
    vector<vector<int>> res_array = solution.threeSum(arrays);
    for (vector<int> iarray : res_array){
        for (int i : iarray){
            cout << i << ' ';
        }
        cout << endl;
    }
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}
