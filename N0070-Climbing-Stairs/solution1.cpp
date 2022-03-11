//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/10/22.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int climbStairs(int n) {
        int i = 0, j = 0, res = 1;
        for (int k = 1; k <= n; ++k) {
            i = j;
            j = res;
            res = i + j;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int n = 3;
    Solution solution;
    cout << solution.climbStairs(n);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


