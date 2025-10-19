//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }
        
        int pos_start = 0;
        int str_len = 1;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // Enumeration string length
        for (int L = 2; L <= n; L++) {
            for (int l_pos = 0; l_pos < n; l_pos++) {
                int r_pos = l_pos + L - 1;
                // if r_pos larger than the border, then break
                if (r_pos >= n) {
                    break;
                }
                
                if (s[l_pos] != s[r_pos]) {
                    dp[l_pos][r_pos] = false;
                } else {
                    if (r_pos - l_pos < 3) {
                        dp[l_pos][r_pos] = true;
                    } else {
                        dp[l_pos][r_pos] = dp[l_pos+1][r_pos-1];
                    }
                }
                
                if(dp[l_pos][r_pos] && r_pos-l_pos+1 > str_len){
                    str_len = r_pos - l_pos + 1;
                    pos_start = l_pos;
                }
            }
        }
        
        return s.substr(pos_start, str_len);
    }

};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    string s ="abbba";
    Solution solution;
    cout << solution.longestPalindrome(s);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

