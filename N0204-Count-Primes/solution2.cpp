//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/7/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    int countPrimes(int n){
        vector<int> isPrime(n,1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]){
                ans += 1;
                if ((long long)i * i < n){
                    for (int j = i*i; j < n; j+=i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int n = 10;
    Solution solution;
    cout << solution.countPrimes(n);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


