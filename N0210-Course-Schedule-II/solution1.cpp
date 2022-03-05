//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/5/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
    vector<vector<int>> edges;
    vector<int> visited; // 0=not search   1=searching   2=finish
    vector<int> result;
    bool  valid = true;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info:prerequisites) {
            edges[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]){
                dfs(i);
            }
        }
        if (!valid){
            return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(int u){
        visited[u] = 1;
        for (int v:edges[u]) {
            if (visited[v] == 0){
                dfs(v);
                if (!valid){
                    return;
                }
            }
            if (visited[v] == 1){
                valid = false;
                return;
            }
        }
        visited[u] = 2;
        result.push_back(u);
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int numCourses = 2;
    vector<vector<int>> prerequisites= {{1, 0}, {0, 1}};
    Solution solution;
    vector<int> sequence = solution.findOrder(numCourses, prerequisites);
    for (int seq: sequence) {
        cout << seq << " ";
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

