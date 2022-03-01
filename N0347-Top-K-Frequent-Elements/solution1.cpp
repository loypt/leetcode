//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/1/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

class Solution{
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v:nums) {
            occurrences[v]++;
        }

        priority_queue<pair<int, int>,vector<pair<int, int>>, decltype(&cmp) > que(cmp);
        for (auto& [num, count]: occurrences) {
            if (que.size() == k){
                if(que.top().second < count) {
                    que.pop();
                    que.emplace(num, count);
                }
            }else {
                que.emplace(num, count);
            }
        }
        vector<int> ret;
        while (!que.empty()){
            ret.emplace_back(que.top().first);
            que.pop();
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution solution;
    vector<int>  res = solution.topKFrequent(nums, k);
    for (int num:res) {
        cout << num << endl;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

