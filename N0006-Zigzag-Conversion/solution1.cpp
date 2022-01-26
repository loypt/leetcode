//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    string convert(string s, int numRows) {
        string res_str;
        if (numRows == 1) {
            return s;
        }
        vector<string> rows_str(numRows > s.length() ? numRows : s.length());
        bool direction = false;
        int cur_row = 0;
        for (int i = 0; i < s.length(); i++) {
            rows_str[cur_row] += s[i];
            if (cur_row == 0 || cur_row == numRows - 1) {
                direction = !direction;
            }
            cur_row += direction ? 1 : -1;
        }
        for (string s : rows_str) {
            res_str += s;
        }
        return res_str;
    }
};
int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    string s ="PAYPALISHIRING";
    Solution solution;
    cout << solution.convert(s, 4);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

