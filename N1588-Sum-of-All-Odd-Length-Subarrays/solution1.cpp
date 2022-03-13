//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/13/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixSums(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSums[i+1] = prefixSums[i] + arr[i];
        }
        int sum  = 0;
        for (int start = 0; start < n; ++start) {
            for (int length = 1; length + start <= n; length += 2) {
                int end = start + length  - 1;
                sum += prefixSums[end+1] - prefixSums[start];
            }
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> arr = {1, 4, 2, 5, 3};
    Solution solution;
    cout << solution.sumOddLengthSubarrays(arr);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

