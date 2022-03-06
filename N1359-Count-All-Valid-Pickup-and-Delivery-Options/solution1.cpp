//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/6/22.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
using LL = long long;

class Solution{
private:
    static constexpr int mod = 1000000007;
public:
    int countOrders(int n){
        if (n == 1){
            return 1;
        }
        int ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans = (LL)ans * (i*2-1) %mod *i % mod;
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int n = 3;
    Solution solution;
    cout << solution.countOrders(n);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

