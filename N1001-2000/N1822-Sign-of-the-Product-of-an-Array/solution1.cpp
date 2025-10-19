//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/11/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt = 0;
        for (const auto& num : nums) {
            if (num == 0){
                return 0;
            }else if(num < 0){
                cnt++;
            }
        }
        return cnt&1 ? -1 : 1;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {-1,-2,-3,-4,3,2,1};
    Solution solution;
    cout << solution.arraySign(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


