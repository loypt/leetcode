//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0, rp = height.size() - 1;
        int maxArea = 0;
        while (lp < rp) {
            int area = min(height[lp], height[rp]) * (rp - lp);
            maxArea = max(area, maxArea);
            if (height[lp] <= height[rp]) {
                ++lp;
            }
            else {
                --rp;
            }
        }
        return maxArea;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    vector<int> int_array = {1,8,6,2,5,4,8,3,7};
    Solution solution;
    cout << solution.maxArea(int_array);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

