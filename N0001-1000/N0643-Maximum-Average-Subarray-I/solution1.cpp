//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/8/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution{
public:
    double findMaxAverage(vector<int>& nums, int k){
        int len = nums.size();
        double sum;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double res = sum;
        for (int right = k; right < len; ++right) {
           sum =  sum + nums[right] - nums[right-k];
           res = max(res, sum);
        }
        return res/k;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    Solution solution;
    cout << solution.findMaxAverage(nums, k);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


