//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/26/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k)
            return 0;
        unordered_set<char> had_chars(s.begin(), s.end());
        unordered_map<char, int> char_count;
        for (char c : s) {
            char_count[c] += 1;
        }
        for (char c:had_chars) {
            vector<string> str_list;
            if (char_count[c] < k) { // exclude situation
                strSplit(s, str_list, c);
                int res = 0;
                for (string str: str_list) {
                    res = max(res, longestSubstring(str, k));
                }
                return res;
            }
        }
        return s.size();
    }

    void strSplit(const string& s, vector<string>& str_list, char exflag = ' ') {
        str_list.clear();
        istringstream iss(s);
        string temp;
        while (getline(iss, temp, exflag)){
            str_list.push_back(temp);
        }
        for (string str:str_list) {
            cout << str << "  ";
        }
        cout << endl;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "abbcabbaaabbcaaabb";
    int k = 3;
    Solution solution;
    cout << solution.longestSubstring(s ,k);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

