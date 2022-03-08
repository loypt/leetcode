//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/8/22.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int countOdds(int low, int high) {
        return ((high%2==1 ? high+1:high)-(low%2==1 ? low-1:low))>>1;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int low = 14, high = 17;
    Solution solution;
    cout <<  solution.countOdds(low, high);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


