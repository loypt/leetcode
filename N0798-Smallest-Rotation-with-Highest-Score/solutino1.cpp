//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/9/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution{
public:
    int bestRotation(vector<int>& nums){
        int len = nums.size();
        vector<int> diffs(len);
        for (int i = 0; i < len; ++i) {
           int low = (i+1)%len;
           int high = (i-nums[i]+len+1)%len;
           diffs[low]++;
           diffs[high]--;
            if (low >= high){
                diffs[0]++;
            }
        }
        int bestIndex = 0;
        int maxScore = 0;
        int score = 0;
        for (int i = 0; i < len; ++i) {
            score += diffs[i];
            if (score > maxScore){
                bestIndex = i;
                maxScore = score;
            }
        }
        return bestIndex;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {2,3,1,4,0};
    Solution solution;
    cout << solution.bestRotation(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


