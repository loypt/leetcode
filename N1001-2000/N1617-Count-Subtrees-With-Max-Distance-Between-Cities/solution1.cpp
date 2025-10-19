class Solution {
public:      
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);        
        for (auto &edge : edges) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }

        function<int(int, int, int)> dfs = [&](int parent, int u, int mask)->int {
            int depth = 0;
            for (int v : adj[u]) {
                if (v != parent && mask & (1 << v)) {
                    depth = max(depth, 1 + dfs(u, v, mask));
                }
            }
            return depth;
        };

        vector<int> ans(n - 1);
        for (int i = 1; i < (1 << n); i++) {
            int x = 32 - __builtin_clz(i) - 1;
            int mask = i;
            int y = -1;
            queue<int> qu;
            qu.emplace(x);
            mask &= ~(1 << x);
            while (!qu.empty()) {
                y = qu.front();
                qu.pop();
                for (int vertex : adj[y]) {
                    if (mask & (1 << vertex)) {
                        mask &= ~(1 << vertex);
                        qu.emplace(vertex);
                    }
                }
            }
            if (mask == 0) {
                int diameter = dfs(-1, y, i);
                if (diameter > 0) {
                    ans[diameter - 1]++;
                }
            }
        }
        return ans;
    }
};
