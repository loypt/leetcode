//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        
        auto single_matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j-1] == '.') {
                return true;
            }
            return s[i-1] == p[j-1];
        };
        
        vector<vector<int>> f(s_size + 1, vector<int>(p_size+1));
        f[0][0] = true;
        for (int i = 0; i <= s_size; ++i) {
            for (int j = 1; j <= p_size; ++j) {
                if (p[j-1] == '*') {
                    f[i][j] = f[i][j-2];
                    if (single_matches(i, j-1)) {
                        f[i][j] |= f[i-1][j];
                    }
                }else {
                    if (single_matches(i, j)) {
                        f[i][j] |= f[i-1][j-1];
                    }
                }
            }
        }
        return f[s_size][p_size];
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    string str1 = "aa";
    string str2 = "a*";
    Solution solution;
    cout << solution.isMatch(str1, str2);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}
