class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int, int>>> g(n);
        for (const auto& edge: edges) {
            g[edge[0]].emplace_back(edge[1], edge[2]);
            g[edge[1]].emplace_back(edge[0], edge[2]);
        }
        
        vector<int> visited(n);
        visited[0] = true;
        int ans = 0;
        
        function<void(int, int, int)> dfs = [&](int u, int time, int value) {
            if (u == 0) {
                ans = max(ans, value);
            }
            for (const auto& [v, dist]: g[u]) {
                if (time + dist <= maxTime) {
                    if (!visited[v]) {
                        visited[v] = true;
                        dfs(v, time + dist, value + values[v]);
                        visited[v] = false;
                    }
                    else {
                        dfs(v, time + dist, value);
                    }
                }
            }
        };
        
        dfs(0, 0, values[0]);
        return ans;
    }
};
