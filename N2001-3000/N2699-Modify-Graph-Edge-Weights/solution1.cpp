class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        int k = 0;
        for (const auto& e: edges) {
            if (e[2] == -1) {
                ++k;
            }
        }

        if (dijkstra(source, destination, construct(n, edges, 0, target)) > target) {
            return {};
        }
        if (dijkstra(source, destination, construct(n, edges, static_cast<long long>(k) * (target - 1), target)) < target) {
            return {};
        }

        long long left = 0, right = static_cast<long long>(k) * (target - 1), ans = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (dijkstra(source, destination, construct(n, edges, mid, target)) >= target) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        for (auto& e: edges) {
            if (e[2] == -1) {
                if (ans >= target - 1) {
                    e[2] = target;
                    ans -= (target - 1);
                }
                else {
                    e[2] = 1 + ans;
                    ans = 0;
                }
            }
        }

        return edges;
    }

    long long dijkstra(int source, int destination, const vector<vector<int>>& adj_matrix) {
        int n = adj_matrix.size();
        vector<long long> dist(n, INT_MAX / 2);
        vector<int> used(n);
        dist[source] = 0;

        for (int round = 0; round < n - 1; ++round) {
            int u = -1;
            for (int i = 0; i < n; ++i) {
                if (!used[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }
            used[u] = true;
            for (int v = 0; v < n; ++v) {
                if (!used[v] && adj_matrix[u][v] != -1) {
                    dist[v] = min(dist[v], dist[u] + adj_matrix[u][v]);
                }
            }
        }

        return dist[destination];
    }

    vector<vector<int>> construct(int n, const vector<vector<int>>& edges, long long idx, int target) {
        vector<vector<int>> adj_matrix(n, vector<int>(n, -1));
        for (const auto& e: edges) {
            int u = e[0], v = e[1], w = e[2];
            if (w != -1) {
                adj_matrix[u][v] = adj_matrix[v][u] = w;
            }
            else {
                if (idx >= target - 1) {
                    adj_matrix[u][v] = adj_matrix[v][u] = target;
                    idx -= (target - 1);
                }
                else {
                    adj_matrix[u][v] = adj_matrix[v][u] = 1 + idx;
                    idx = 0;
                }
            }
        }
        return adj_matrix;
    }
};
