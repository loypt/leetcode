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

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int len = customers.size();
        vector<int> preSum(len+1);

        int originCount = 0;
        for (int i = 0; i < len; ++i) {
            if (grumpy[i]==0){
                originCount += customers[i];
                preSum[i+1] = preSum[i];
            }else{
                preSum[i+1]=preSum[i]+customers[i];
            }
        }

        int maxCount = 0;
        for (int left = 0; left < len-minutes+1; ++left) {
           maxCount = max(maxCount, preSum[left+minutes]-preSum[left]);
        }

        return originCount+maxCount;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int X = 3;
    Solution solution;
    cout << solution.maxSatisfied(customers, grumpy, X);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


