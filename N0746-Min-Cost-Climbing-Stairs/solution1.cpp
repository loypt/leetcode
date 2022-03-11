//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/10/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        int p = 0, q = 0, r = 0;
        for (int i = 2; i <= len; ++i) {
            p = q;
            q = r;
            r = min(q+cost[i-1], p+cost[i-2]);
        }
        return r;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> cost = {10, 15, 20};
    Solution solution;
    cout << solution.minCostClimbingStairs(cost);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


