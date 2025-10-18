//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/13/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m){
            return false;
        }
        vector<int> cnt(26);
        for (int i = 0; i < n; ++i) {
            --cnt[s1[i]-'a'];
            ++cnt[s2[i]-'a'];
        }
        int diff = 0;
        for(const auto& c :cnt){
            if (c != 0){
                ++diff;
            }
        }

        if (diff == 0){
            return true;
        }
        for (int i = n; i < m; ++i) {
            int x  = s2[i]-'a', y = s2[i-n]-'a'; // x in, y out
            if (x == y){
                continue;
            }
            if (cnt[x] == 0){
                ++diff;
            }
            ++cnt[x];
            if (cnt[x] == 0){
                --diff;
            }
            if(cnt[y] == 0){
                ++diff;
            }
            --cnt[y];
            if (cnt[y] == 0){
                --diff;
            }
            if (diff == 0){
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s1 = "ab";
    string s2 = "eidbaooo";
    Solution solution;
    cout << solution.checkInclusion(s1, s2);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

