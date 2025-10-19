//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/9/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int maxVowels(string s, int k) {
        int len = s.size();
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += isVower(s[i]);
        }
        int ans = cnt;
        for (int j = k; j < len; ++j) {
            cnt += isVower(s[j]) - isVower(s[j-k]);
            ans = max(cnt, ans);
        }
        return ans;
    }

    bool isVower(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "abciiidef";
    int k = 3;
    Solution solution;
    cout << solution.maxVowels(s, k);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


