class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        vector<vector<int>> neighbors(n);
        for (int i = 0; i < n - 1; i++) {
            neighbors[i].push_back(i + 1);
        }
        vector<int> res;
        for (auto &query : queries) {
            neighbors[query[0]].push_back(query[1]);
            res.push_back(bfs(n, neighbors));
        }
        return res;
    }

    int bfs(int n, const vector<vector<int>> &neighbors) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : neighbors[x]) {
                if (dist[y] >= 0) {
                    continue;
                }
                q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
        return dist[n - 1];
    }
};
