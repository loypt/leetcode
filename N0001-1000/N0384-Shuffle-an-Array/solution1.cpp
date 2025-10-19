//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/27/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    Solution(vector<int>& nums) : v(nums), s(nums) {}

    vector<int> reset() {
        return v;
    }

    vector<int> shuffle() {
        for (int i = 1; i < s.size(); ++i) swap(s[i], s[i - rand() % (i+1)]);
        return s;
    }

private:
    vector<int>& v, s;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1, 2,3};
    Solution solution(nums);
    vector<int> reset_nums = solution.reset();
    for (int num:reset_nums) {
        cout << num << " ";
    }
    vector<int> shuffle_nums = solution.shuffle();
    for (int num:shuffle_nums) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

