//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/9/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        int minSum, sum = 0;
        int left = 0, right = len-k;
        for (int i = left; i < right; ++i) {
            sum += cardPoints[i];
        }
        minSum = sum;
        for (int i = right; i < len; ++i) {
            sum += cardPoints[i]-cardPoints[left++];
            minSum = min(sum, minSum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0)-minSum;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    Solution solution;
    cout << solution.maxScore(cardPoints, k);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


