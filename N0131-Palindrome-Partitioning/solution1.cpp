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
#include <math.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> ans;
    vector<vector<int>> parray;
    int len;
    vector<vector<string>> partition(string s) {
        // judge string's part Palindrome
        len = s.size();
        parray.assign(len, vector<int>(len, true));
        
        for (int i = len-1; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                parray[i][j] =  parray[i+1][j-1] && (s[i] == s[j]);
            }
        }
        
        // and we get all part of string is palindrome
        dfs(s, 0);
        
        return res;
    }
    
    void dfs(const string& s, int i) {
        if (i == len) { // round ends
            res.push_back(ans);
            return;
        }
        for (int j=i; j < len; ++j) {
            if (parray[i][j]) { // is palindrome
                ans.push_back(s.substr(i, j-i+1));
                dfs(s, j+1);
                ans.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    string s = "aab";
    Solution solution;
    vector<vector<string>> res_vector = solution.partition(s);
    for (vector<string> strlist : res_vector) {
        for (string s : strlist) {
            cout << s << " ";
        }
        cout << endl;
    }
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

