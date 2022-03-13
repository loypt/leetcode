//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/13/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> set;
        int repeat = -1;
        for(const auto& num : nums){
            if (!set.insert(num).second){
                repeat  =num;
                break;
            }
        }
        return repeat;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums= {2, 3, 1, 0, 2, 5, 3};
    Solution solution;
    cout << solution.findRepeatNumber(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

