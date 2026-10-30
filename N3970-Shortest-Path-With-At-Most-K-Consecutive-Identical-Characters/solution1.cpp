class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> g(n);
        for (auto& e : edges) g[e[0]].push_back({e[1], e[2]});
        const long long INF = (1LL << 60);
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));
        using Node = tuple<long long, int, int>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top(); pq.pop();
            if (d != dist[u][cnt]) continue;
            if (u == n - 1) return (int)d;
            for (auto [v, w] : g[u]) {
                int nc = (labels[v] == labels[u]) ? cnt + 1 : 1;
                if (nc > k) continue;
                long long nd = d + w;
                if (nd < dist[v][nc]) {
                    dist[v][nc] = nd;
                    pq.push({nd, v, nc});
                }
            }
        }
        long long ans = INF;
        for (int c = 1; c <= k; c++) ans = min(ans, dist[n - 1][c]);
        return ans == INF ? -1 : (int)ans;
    }
};
