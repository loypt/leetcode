//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/1/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            int x = i;
            while (x){
                count++;
                x&=(x-1); // Brian Kernighan, remove the last one
            }
            res.push_back(count);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int n;
    cin >> n;
    Solution solution;
    vector<int> res = solution.countBits(n);
    for (int n:res) {
        cout << n << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

