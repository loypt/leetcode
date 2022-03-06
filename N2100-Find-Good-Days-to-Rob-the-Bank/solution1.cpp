//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/6/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int len = security.size();
        vector<int> left(len);
        vector<int> right(len);
        for (int i = 1; i < len; ++i) {
            if (security[i] <= security[i-1]){
                left[i] = left[i-1]+1;
            }
            if (security[len-i-1] <= security[len-i]) {
                right[len-i-1] = right[len-i]+1;
            }
        }
        vector<int> ans;
        for (int i = 0; i < len-time; ++i) {
            if (left[i] >= time && right[i] >= time){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> security = {5,3,3,3,5,6,2};
    int time = 2;
    Solution solution;
    vector<int> res = solution.goodDaysToRobBank(security, time);
    for (const auto& num: res) {
        cout << num <<  " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

