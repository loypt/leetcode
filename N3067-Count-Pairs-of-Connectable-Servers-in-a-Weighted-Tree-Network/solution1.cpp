class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> graph(n);
        
        for (auto e : edges) {
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2]);
        }
        function<int(int, int, int)> dfs = [&](int p, int root, int curr) -> int {
            int res = 0;
            if (curr == 0) {
                res++;
            }
            for (auto &[v, cost] : graph[p]) {
                if (v != root) {
                    res += dfs(v, p, (curr + cost) % signalSpeed);
                }
            }
            return res;
        };
        
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int pre = 0;
            for (auto &[v, cost] : graph[i]) {
                int cnt = dfs(v, i, cost % signalSpeed);
                res[i] += pre * cnt;
                pre += cnt;
            }
        }
        return res;
    }
};
