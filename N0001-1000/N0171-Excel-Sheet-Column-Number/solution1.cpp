//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/26/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        // Hashtable
        int len = columnTitle.size();
        int res = 0;
        for (char c : columnTitle) {
            res += pow(26, --len)*(c-64);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    printf("%d  ", 'A');
    string columnTitle = "ZY";
    Solution solution;
    cout << solution.titleToNumber(columnTitle);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

