//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0) && (x != 0)) {
            return false;
        }
        int reversedNum = 0;
        while (x > reversedNum) {
            reversedNum = reversedNum * 10 + x % 10;
            x /= 10;
        }
        if (x == reversedNum || x == reversedNum / 10) {
            return true;
        }else {
            return false;
        }
    }
};
int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    int num = 121;
    Solution solution;
    cout << solution.isPalindrome(num);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}
