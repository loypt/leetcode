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
    int getSum(int a, int b) {
        while(b!=0){
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a^b;
            b = carry;
        }
        return a;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int a = 1, b = 2;
    Solution solution;
    cout << solution.getSum(a, b);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


