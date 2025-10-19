//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/11/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size()-1; ++i) {
            if (arr[i] * 2 != arr[i-1]+arr[i+1]){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {3,5,1};
    Solution solution;
    cout << solution.canMakeArithmeticProgression(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


