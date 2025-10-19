//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/13/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> setchar;
        int len = s.size();
        int rk = -1, res = 0;
        for (int i = 0; i < len; ++i) {
            if (i != 0){
                setchar.erase(s[i-1]);
            }
            while (rk+1 < len && !setchar.count(s[rk+1])){
                setchar.insert(s[rk+1]);
                ++rk;
            }
            res = max(res, rk+1-i);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "abcabcbb";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

