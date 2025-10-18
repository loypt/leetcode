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
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32 && n > 0; ++i) {
            cout << "n&1: " <<  bitset<32>(n&1) << endl; // n&1: get the last bit
            res |= (n & 1) << (31-i);
            cout << "res: " << bitset<32>(res) << endl;
            n >>= 1;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    const uint32_t n = 43261596;
    cout << "Input: " << bitset<32>(n) << endl;
    Solution solution;
    cout << bitset<32>(solution.reverseBits(n));
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


