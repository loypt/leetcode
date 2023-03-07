//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/6/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

class Solution {
private:
    int gcd(int x, int y){
        return y!=0 ? gcd(y, x % y) : x;
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> s; // use vector to simulation stack
        int len = nums.size();
        s.push_back(nums[0]);
        for (int i = 1; i < len; ++i) {
            s.push_back(nums[i]);
            while (s.size() > 1){
                int x = s.back(), y = s[s.size()-2];
                int g = gcd(x, y);
                if (g == 1){ // gcd equal 1, then skip
                    break;
                }
                s.pop_back();
                s.back() *= x/g;
            }
        }
        return s;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {6,4,3,2,7,6,2};
    Solution solution;
    vector<int> res = solution.replaceNonCoprimes(nums);
    for (const auto& num: res) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


