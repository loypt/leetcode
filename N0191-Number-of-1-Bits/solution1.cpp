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
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            res += n & 1 ? 1 : 0;
            n >>= 1;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    const uint32_t n = 11;
    cout << bitset<32>(n) << endl;
    Solution solution;
    cout << solution.hammingWeight(n);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


