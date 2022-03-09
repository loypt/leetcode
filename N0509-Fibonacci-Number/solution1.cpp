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

class Solution{
public:
    int fib(int n){
        if (n < 2){
            return n;
        }
        int fi = 0, si = 0, res = 1;
        for (int i = 2; i <= n ; ++i) {
            fi = si;
            si = res;
            res = fi + si;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int num = 2;
    Solution solution;
    cout << solution.fib(num);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


