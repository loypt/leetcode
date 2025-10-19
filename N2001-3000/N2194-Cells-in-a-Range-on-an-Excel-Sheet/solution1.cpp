//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/6/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<char> schar;
        vector<string> res;
        for (char c:s) {
            if (c != ':'){
                schar.push_back(c);
            }
        }
        for (int i = schar[0]; i <= schar[2]; ++i) {
            for (int j = schar[1]; j <= schar[3]; ++j) {
                string s = "";
                s += (char)i;
                s += (char)j;
                res.push_back(s);
            }
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "A1:F1";
    Solution solution;
    vector<string> res = solution.cellsInRange(s);
    for (const auto& str: res) {
        cout << str << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

