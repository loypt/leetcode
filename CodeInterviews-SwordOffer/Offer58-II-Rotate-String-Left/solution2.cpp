//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/12/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res;
        for (int i = n; i < s.size()+n; ++i) {
            res += s[i % s.size()];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "abcdefg";
    int k = 2;
    Solution solution;
    cout << solution.reverseLeftWords(s, k);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


