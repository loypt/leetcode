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
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int len = s.length();
        vector<int> preSum(len);
        for (int i = 0, sum=0; i < len; ++i) {
            if (s[i] == '*'){
                sum++;
            }
            preSum[i] = sum;
        }

        // left
        vector<int> left(len);
        for (int i = 0, l = -1; i < len; ++i) {
            if (s[i] == '|'){
                l = i;
            }
            left[i] = l;
        }

        // right
        vector<int> right(len);
        for (int i = len-1, r = -1 ; i >= 0; --i) {
            if (s[i] == '|'){
                r = i;
            }
            right[i] = r;
        }

        vector<int> res;
        for (const auto& query:queries) {
            int x = right[query[0]], y = left[query[1]];
            res.push_back(x == -1 || y == -1 || x >= y ? 0 : preSum[y]-preSum[x]);
        }

        return res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "**|**|***|";
    vector<vector<int>> queries = {{2, 5}, {5, 9}};
    Solution solution;
    vector<int> resArray = solution.platesBetweenCandles(s, queries);
    for (const auto& num:resArray) {
        cout << num << endl;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


