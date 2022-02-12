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
        int maxTemp = 0;
        for (int i = 1; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++){
                maxTemp = max(min(height[i], height[j]) * (j - i), maxTemp);
            }
        }
        return maxTemp;
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
