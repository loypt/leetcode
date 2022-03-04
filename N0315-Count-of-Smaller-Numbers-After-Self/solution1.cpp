//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/1/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

using namespace std;
using namespace std::chrono;

class Solution {
private:
    vector<int> a;
    vector<int> c;

    void init(int len) {
        c.resize(len);
    }

    // the lowest bit of x
    int lowbit(int x) {
        return x & (-x);
    }

    void update(int pos) {
        while (pos < c.size()) {
            c[pos] += 1;
            pos += lowbit(pos);
        }
    }

    // sum of [0,...,pos]
    int query(int pos) {
        int res = 0;
        while (pos) {
            res += c[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    void Discretization(vector<int>& nums) {
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }

    int getId(int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        init(n+1);
        Discretization(nums);

        for (int i=n-1; i>=0; --i) {
            int id = getId(nums[i]);
            res.push_back(query(id-1));
            update(id);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {5,2,6,1};
    Solution solution;
    vector<int> res =  solution.countSmaller(nums);
    for (int num:res) {
        cout << num << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

