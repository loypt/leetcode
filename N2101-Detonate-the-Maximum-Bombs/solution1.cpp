class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        auto isConnected = [&](int u, int v) -> bool {
            long long dx = bombs[u][0] - bombs[v][0];
            long long dy = bombs[u][1] - bombs[v][1];
            return (long long)bombs[u][2] * bombs[u][2] >= dx * dx + dy * dy;
        };
        
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && isConnected(i, j)) {
                    edges[i].push_back(j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> visited(n);
            int cnt = 1;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty()) {
                int cidx = q.front();
                q.pop();
                for (const int nidx: edges[cidx]) {
                    if (visited[nidx]) {
                        continue;
                    }
                    ++cnt;
                    q.push(nidx);
                    visited[nidx] = 1;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};
