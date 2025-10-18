class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], length = edge[2];
            adj[u].emplace_back(v, length);
            adj[v].emplace_back(u, length);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        vector<int> answer(n, -1);
        answer[0] = 0;
        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();
            if (t != answer[u]) {
                continue;
            }
            for (const auto& [v, length] : adj[u]) {
                if (t + length < disappear[v] && (answer[v] == -1 || t + length < answer[v])) {
                    pq.emplace(t + length, v);
                    answer[v] = t + length;
                }
            }
        }
        return answer;
    }
};
