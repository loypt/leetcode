class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> g(numCourses);
        vector<int> indgree(numCourses, 0);
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        for (auto& p : prerequisites) {
            ++indgree[p[1]];
            g[p[0]].push_back(p[1]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indgree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto& ne : g[cur]) {
                isPre[cur][ne] = true;
                for (int i = 0; i < numCourses; ++i) {
                    isPre[i][ne] = isPre[i][ne] | isPre[i][cur];
                }
                --indgree[ne];
                if (indgree[ne] == 0) {
                    q.push(ne);
                }
            }
        }
        vector<bool> res;
        for (auto& query : queries) {
            res.push_back(isPre[query[0]][query[1]]);
        }
        return res;
    }
};
