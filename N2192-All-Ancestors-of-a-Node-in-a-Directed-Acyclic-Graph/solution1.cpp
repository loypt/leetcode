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
private:
    vector<vector<int>> graph, ans;
    int n;
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph = vector<vector<int>>(n);
        ans = vector<vector<int>>(n);

        for (const auto& edge:edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n);
            dfs(i, i, visited);
        }
        for (int i = 0; i < n; ++i) {
            sort(ans[i].begin(), ans[i].end());
        }

        return ans;
    }

    void dfs(int i, int u, vector<bool> &visited){
        for (const auto& v:graph[u]) {
            if (!visited[v]){
                visited[v] = true;
                ans[v].push_back(i);
                dfs(i, v, visited);
            }
        }
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int n = 8;
    vector<vector<int>> edgeList = {{0,3}, {0,4}, {1,3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7},{4, 6}};
    Solution solution;
    vector<vector<int>> resArray = solution.getAncestors(n, edgeList);
    for (const auto& list: resArray) {
        for (const auto& num:list) {
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


