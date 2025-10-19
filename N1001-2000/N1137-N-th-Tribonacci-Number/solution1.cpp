//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/9/22.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0){
            return 0;
        }
        if (n <= 2){
            return 1;
        }
        int p=0, q=0, r=1, s=1;
        for (int i = 3; i <= n; ++i) {
           p = q;
           q = r;
           r = s;
           s = p + q + r;
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int num = 4;
    Solution solution;
    cout << solution.tribonacci(num);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


