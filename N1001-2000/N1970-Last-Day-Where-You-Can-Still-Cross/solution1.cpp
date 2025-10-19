class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = row * col, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            
            vector<vector<int>> grid(row, vector<int>(col, 1));
            for (int i = 0; i < mid; ++i) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 0;
            }

            queue<pair<int, int>> q;
            for (int i = 0; i < col; ++i) {
                if (grid[0][i]) {
                    q.emplace(0, i);
                    grid[0][i] = 0;
                }
            }
            bool found = false;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirs[d][0];
                    int ny = y + dirs[d][1];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny]) {
                        if (nx == row - 1) {
                            found = true;
                            break;
                        }
                        q.emplace(nx, ny);
                        grid[nx][ny] = 0;
                    }
                }
            }
            if (found) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
