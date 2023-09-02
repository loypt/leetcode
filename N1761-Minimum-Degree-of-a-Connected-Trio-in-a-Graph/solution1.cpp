class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n);
        vector<vector<int>> h(n);
        vector<int> degree(n);

        for (auto&& edge: edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            g[x].insert(y);
            g[y].insert(x);
            ++degree[x];
            ++degree[y];
        }
        for (auto&& edge: edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            if (degree[x] < degree[y] || (degree[x] == degree[y] && x < y)) {
                h[x].push_back(y);
            }
            else {
                h[y].push_back(x);
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j: h[i]) {
                for (int k: h[j]) {
                    if (g[i].count(k)) {
                        ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
