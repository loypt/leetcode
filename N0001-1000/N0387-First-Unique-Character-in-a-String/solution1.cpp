//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <unordered_map>
#include <array>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int firstUniqChar(string s) {
        // frequency
        unordered_map<int, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "loveleetcode";
    Solution solution;
    cout << solution.firstUniqChar(s);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

