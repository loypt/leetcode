//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wdSet = unordered_set<string> ();
        for (auto word : wordDict) {
            wdSet.insert(word);
        }

        auto dp = vector<bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wdSet.find(s.substr(j, i - j)) != wdSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "leetcode";
    vector<string> workDict = {"leet","code"};
    Solution solution;
    cout << solution.wordBreak(s, workDict);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

