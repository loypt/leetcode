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
    string minWindow(string s, string t) {
        vector<int> window(128);
        vector<int> pattern(128);

        for (const auto& c :t) {
            pattern[c-'A']++;
        }
        int distance = 0;

        for (int i = 0; i < 128; ++i) {
            if (pattern[i] > 0){
                distance++;
            }
        }
        int slen = s.length();
        int start = 0, left = 0, right = 0, match = 0;
        int minLen = slen+1;

        while(right < slen){
            char curChar = s[right];
            if (pattern[curChar-'A'] > 0){
                window[curChar-'A']++;
                if (window[curChar - 'A'] == pattern[curChar-'A']){
                    match++;
                }
            }
            right++;
            while (match == distance){
                if (right-left < minLen){
                    start = left;
                    minLen = right - left;
                }
                char leftChar = s[left];
                if (pattern[leftChar-'A'] > 0){
                    window[leftChar - 'A']--;

                    if (window[leftChar - 'A'] < pattern[leftChar - 'A']){
                        match--;
                    }
                }
                left++;
            }
        }

        return minLen == slen + 1 ? "" : s.substr(start, minLen);
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "abc";
    string t = "b";
    Solution solution;
    cout << solution.minWindow(s, t);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


