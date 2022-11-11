class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sx = 0, sy = 0;
        unordered_map<char, int> key_to_idx;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
                else if (islower(grid[i][j])) {
                    if (!key_to_idx.count(grid[i][j])) {
                        int idx = key_to_idx.size();
                        key_to_idx[grid[i][j]] = idx;
                    }
                }
            }
        }

        queue<tuple<int, int, int>> q;
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(1 << key_to_idx.size(), -1)));
        q.emplace(sx, sy, 0);
        dist[sx][sy][0] = 0;
        while (!q.empty()) {
            auto [x, y, mask] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != '#') {
                    if (grid[nx][ny] == '.' || grid[nx][ny] == '@') {
                        if (dist[nx][ny][mask] == -1) {
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
                    }
                    else if (islower(grid[nx][ny])) {
                        int idx = key_to_idx[grid[nx][ny]];
                        if (dist[nx][ny][mask | (1 << idx)] == -1) {
                            dist[nx][ny][mask | (1 << idx)] = dist[x][y][mask] + 1;
                            if ((mask | (1 << idx)) == (1 << key_to_idx.size()) - 1) {
                                return dist[nx][ny][mask | (1 << idx)];
                            }
                            q.emplace(nx, ny, mask | (1 << idx));
                        }
                    }
                    else {
                        int idx = key_to_idx[tolower(grid[nx][ny])];
                        if ((mask & (1 << idx)) && dist[nx][ny][mask] == -1) {
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
                    }
                }
            }
        }
        return -1;
    }

private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
