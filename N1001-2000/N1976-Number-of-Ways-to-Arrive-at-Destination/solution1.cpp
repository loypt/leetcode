class Solution {
public:
    using LL = long long;
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long mod = 1e9 + 7;
        vector<vector<pair<int, int>>> e(n);
        for (const auto& road : roads) {
            int x = road[0], y = road[1], t = road[2];
            e[x].emplace_back(y, t);
            e[y].emplace_back(x, t);
        }
        vector<long long> dis(n, LLONG_MAX);
        vector<long long> ways(n);

        priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> q;
        q.emplace(0, 0);
        dis[0] = 0;
        ways[0] = 1;
        
        while (!q.empty()) {
            auto [t, u] = q.top();
            q.pop();
            if (t > dis[u]) {
                continue;
            }
            for (auto &[v, w] : e[u]) {
                if (t + w < dis[v]) {
                    dis[v] = t + w;
                    ways[v] = ways[u];
                    q.emplace(t + w, v);
                } else if (t + w == dis[v]) {
                    ways[v] = (ways[u] + ways[v]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};
