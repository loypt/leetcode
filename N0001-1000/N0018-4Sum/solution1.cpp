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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadRes;
        // must greater than 4 values
        if (nums.size() < 4) {
            return quadRes;
        }
        
        // sort the vector list
        sort(nums.begin(), nums.end());
        
        int length = nums.size();
        for (int i = 0; i < length - 3; i++) {
            // if have repeat digit, then jump to next
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            // cut branch
            if ((long) nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }
            if ((long) nums[i] + nums[length-3] + nums[length-2] + nums[length-1] < target) {
                continue;
            }
            
            for (int j = i+1; j < length - 2; j++) {
                // if repeat, then jump to next
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                // cut branch
                if ((long) nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {
                    break;
                }
                if ((long) nums[i] + nums[j] + nums[length-2] + nums[length-1] < target) {
                    continue;
                }
                
                // two sum
                int li = j+1, ri = length-1;
                while (li < ri) {
                    int sum = nums[i] + nums[j] + nums[li] + nums[ri];
                    
                    // find the target, and push to res vector
                    if (sum == target) {
                        quadRes.push_back({nums[i], nums[j], nums[li], nums[ri]});
                        // if repeat, then jump to next
                        while (li < ri && nums[li] == nums[li+1]) {
                            li++;
                        }
                        li++;
                        while (li < ri && nums[ri] == nums[ri-1]) {
                            ri--;
                        }
                        ri--;
                    } else if(sum < target) {
                        li++;
                    } else {
                        ri--;
                    }
                }
            }
        }
        
        return quadRes;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    Solution solution;
    
    //Output normal constant
    /*
     cout << solution.letterCombinations(digits);
     */
    
    // Output Vectors
    vector<vector<int>> res = solution.fourSum(nums, target);
    for(vector<int> vi: res){
        for (int i: vi) {
            cout << i << ", ";
        }
        cout << endl;
    }
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}
