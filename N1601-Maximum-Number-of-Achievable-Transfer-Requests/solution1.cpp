//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/27/22.
//

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> emp_change_count(n); //
        int ans = 0, m = requests.size();
        for (int mask = 0; mask < (1 << m); ++mask) { // 1 left shift m bit
            int request_count = __builtin_popcount(mask); // __builtin_popcount: count 1, request count
            if (request_count <= ans) {
                continue;
            }
            fill(emp_change_count.begin(), emp_change_count.end(), 0);
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    ++emp_change_count[requests[i][0]];
                    --emp_change_count[requests[i][1]];
                }
            }
            if (all_of(emp_change_count.begin(), emp_change_count.end(), [](int x) { return x == 0;})){ // check all value satisfy expression
                ans = request_count;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int n = 5;
    vector<vector<int>> requests = {{0, 1},{1,0},{0,1}, {1,2},{2,0}};
    Solution solution;
    cout << solution.maximumRequests(n, requests);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

