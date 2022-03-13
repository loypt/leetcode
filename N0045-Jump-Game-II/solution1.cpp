//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/12/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int jump(vector<int>& nums) {
        int position = nums.size()-1;
        int step = 0;
        while (position > 0){
            for (int i = 0; i < position; ++i) {
                if (i+nums[i] >= position){
                    position = i;
                    step++;
                    break;
                }
            }
        }
        return step;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int>  nums = {2,3,1,1,4};
    Solution solution;
    cout << solution.jump(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


