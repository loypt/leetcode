//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/7/22.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    int trailingZeroes(int n) {
        int fiveCount = 0;
        while(n >= 5){
            fiveCount += n / 5;
            n /= 5;
        }
        return fiveCount;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int n = 25;
    Solution solution;
    cout<< solution.trailingZeroes(n);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


