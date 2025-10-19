//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/11/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()){
            return false;
        }
        int cnt = 0, m = -1, n = -1;
        for (int i = 0, j = 0; i < s1.size(); ++i, ++j) {
            if (s1[i] != s2[j]){
                cnt++;
                if (m == -1) m = i;
                if (n == -1 && m != i) n = j;
            }
        }
        if (cnt == 0) return true;
        if (cnt == 2 && s1[m] == s2[n] && s2[m] == s1[n]){
            return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s1 = "bank";
    string s2 = "kanb";
    Solution solution;
    cout << solution.areAlmostEqual(s1, s2);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


