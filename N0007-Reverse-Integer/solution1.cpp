//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <math.h>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    int reverse(int x) {
        int remainder, res = 0;
        while (x) {
            if (res < INT_MIN / 10 || res > INT_MAX / 10) {
                return 0;
            }
            remainder = x % 10;
            res = res * 10 + remainder;
            x = x/10;
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    Solution solution;
    cout << solution.reverse(12345);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

