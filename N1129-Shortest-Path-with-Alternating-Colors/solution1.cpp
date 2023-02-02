class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> next(2, vector<vector<int>>(n));
        for (auto &e : redEdges) {
            next[0][e[0]].push_back(e[1]);
        }
        for (auto &e : blueEdges) {
            next[1][e[0]].push_back(e[1]);
        }

        vector<vector<int>> dist(2, vector<int>(n, INT_MAX)); // 两种类型的颜色最短路径的长度
        queue<pair<int, int>> q;
        dist[0][0] = 0;
        dist[1][0] = 0;
        q.push({0, 0});
        q.push({0, 1});
        while (!q.empty()) {
            auto [x, t] = q.front();
            q.pop();
            for (auto y : next[1 - t][x]) {
                if (dist[1 - t][y] != INT_MAX) {
                    continue;
                }
                dist[1 - t][y] = dist[t][x] + 1;
                q.push({y, 1 - t});
            }
        }
        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            answer[i] = min(dist[0][i], dist[1][i]);
            if (answer[i] == INT_MAX) {
                answer[i] = -1;
            }
        }
        return answer;
    }
};
