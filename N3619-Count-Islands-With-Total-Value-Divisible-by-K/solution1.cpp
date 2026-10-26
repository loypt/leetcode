class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<char>> vis(m, vector<char>(n, 0));
        int ans = 0;
        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] <= 0 || vis[i][j]) continue;
                long long sum = 0;
                vector<pair<int, int>> st;
                st.emplace_back(i, j);
                vis[i][j] = 1;
                while (!st.empty()) {
                    auto [x, y] = st.back();
                    st.pop_back();
                    sum += grid[x][y];
                    for (auto d : dirs) {
                        int nx = x + d[0], ny = y + d[1];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (grid[nx][ny] <= 0 || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        st.emplace_back(nx, ny);
                    }
                }
                if (sum % k == 0) ans++;
            }
        }
        return ans;
    }
};
