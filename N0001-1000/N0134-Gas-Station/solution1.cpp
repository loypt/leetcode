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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while(i < n){
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while(cnt < n){
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas){
                    break;
                }
                cnt++;
            }
            if (cnt == n){
                return i;
            }else {
                i = i+cnt+1;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    Solution solution;
    cout << solution.canCompleteCircuit(gas, cost);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


