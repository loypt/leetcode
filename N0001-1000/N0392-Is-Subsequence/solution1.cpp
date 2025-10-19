//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/2/22.
//

#include <iostream>
#include <chrono>
#include <numeric>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j= 0;
        while (i < s.length() && j < t.length()){
            if (s[i] == t[j]){
                i++;
            }
            j++;
        }
        return i == s.length();
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "abc";
    string t = "ahbgdc";
    Solution solution;
    cout << solution.isSubsequence(s, t);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

