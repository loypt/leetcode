//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/11/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
    int len;
    long maxScore = 0;
    int cnt = 0;
    vector<vector<int>> children;
public:
    int countHighestScoreNodes(vector<int>& parents) {
        this->len =  parents.size();
        this->children = vector<vector<int>>(len);
        for (int i = 0; i < len; ++i) {
            int p = parents[i];
            if (p != -1){
                children[p].emplace_back(i);
            }
        }
        dfs(0);
        return cnt;
    }

    int dfs(int node){
        int size  = len-1;
        long score = 1;
        for (const auto& n:children[node]) {
            int t = dfs(n);
            score *= t;
            size -= t;
        }
        if (node != 0){
            score *= size;
        }
        if (score == maxScore){
            cnt++;
        }else if(score > maxScore){
            maxScore = score;
            cnt = 1;
        }
        return len-size;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<int> parents = {-1, 2, 0, 2, 0};
    Solution solution;
    cout << solution.countHighestScoreNodes(parents);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


