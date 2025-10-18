//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <math.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int superEggDrop(int k, int n) {
        return dp(k, n);
    }
    unordered_map<int, int> memo;
    int dp(int k, int n) {
        if(memo.find(n*50+k) == memo.end()){ // if find failed
            int res;
            if (n == 0) { // if zero floor
                res = 0;
            } else if (k == 1) { // if only one egg
                res = n;
            } else { // binary search
                int low = 1, high = n;
                while (low+1 < high) {
                    int x = (low + high) / 2;
                    int t1 = dp(k-1, x-1); // if break
                    int t2 = dp(k, n-x); // not break
                    
                    if (t1 > t2) {
                        high = x;
                    }else if (t1 < t2){ //not break
                        low = x;
                    }else {
                        low = high = x;
                    }
                }
                
                res = 1 + min(max(dp(k-1, low-1), dp(k, n-low)), max(dp(k-1, high-1), dp(k, n-high)));
            }
            
            memo[n*50 + k] = res;
        }
        
        return memo[n*50+k];
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    int k = 13;
    int n = 8191;
    Solution solution;
    cout << solution.superEggDrop(k, n);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

