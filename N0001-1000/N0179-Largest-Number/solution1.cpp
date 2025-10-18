//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/26/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int i, int j){
            string istr = to_string(i);
            string jstr = to_string(j);
            return istr+jstr > jstr+istr;
        });
        string res;
        for (int num:nums) {
            res += to_string(num);
        }
        if (res[0] == '0'){
            return "0";
        }else{
            return res;
        }
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {3,30,34,5,9};
    Solution solution;
    cout << solution.largestNumber(nums);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

