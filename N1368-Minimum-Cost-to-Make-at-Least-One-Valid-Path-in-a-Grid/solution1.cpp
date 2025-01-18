using PII = pair<int, int>;

class Solution {
private:
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dist(m * n, INT_MAX);
        vector<int> seen(m * n, 0);
        dist[0] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.emplace(0, 0);
        
        while (!q.empty()) {
            auto [cur_dis, cur_pos] = q.top();
            q.pop();
            if (seen[cur_pos]) {
                continue;
            }
            seen[cur_pos] = 1;
            int x = cur_pos / n;
            int y = cur_pos % n;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                int new_pos = nx * n + ny;
                int new_dis = cur_dis + (grid[x][y] != i + 1);
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && new_dis < dist[new_pos]) {
                    dist[new_pos] = new_dis;
                    q.emplace(new_dis, new_pos);
                }
            }
        }

        return dist[m * n - 1];
    }
};
