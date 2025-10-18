class Solution {
private:
    int num = 0;
    vector<int> dfn, low;
    vector<vector<int>> res;
    vector<vector<int>> adj;

    void tarjan(int u, int fa) {
        dfn[u] = low[u] = ++num;
        for (int v : adj[u]) {
            if (v == fa) continue;
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (dfn[u] < low[v]) res.push_back({u, v});
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dfn.resize(n);
        low.resize(n);
        adj.resize(n);
        for (auto edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (int u = 0; u < n; u++) {
            if (!dfn[u]) tarjan(u, -1);
        }
        return res;
    }
};
