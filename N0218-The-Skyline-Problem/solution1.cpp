//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/4/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        auto cmp = [](const pair<int ,int>& a, const pair<int ,int>& b) -> bool {return a.second < b.second;};
        priority_queue<pair<int , int>, vector<pair<int, int>>, decltype(cmp)> my_que(cmp);

        // put x to boundaries, and sort with pos
        vector<int> boundaries;
        for (auto& building:buildings) {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());

        vector<vector<int>> res;
        int len = buildings.size(), pos = 0;
        for (auto& boundary:boundaries) {
            while (pos < len && buildings[pos][0] <= boundary){
                my_que.emplace(buildings[pos][1], buildings[pos][2]);
                pos++;
            }
            while (!my_que.empty() && my_que.top().first <= boundary) {
                my_que.pop();
            }
            int maxn = my_que.empty() ? 0 : my_que.top().second;
            if (res.size() == 0 || maxn != res.back()[1]){
                res.push_back({boundary, maxn});
            }
        }
        return res;
    }
};



int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    Solution solution;
    vector<vector<int>> res = solution.getSkyline(buildings);
    for(const vector<int>& nums : res){
        for (int num:nums) {
            cout << num << " ";
        }
        cout << endl;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

