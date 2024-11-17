class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int cnt1 = grid[i][j] + grid[i][n - 1 - j] +
                           grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j];
                ans += min(cnt1, 4 - cnt1);
            }
        }

        int diff = 0, cnt1 = 0;
        if (m & 1) {
            for (int j = 0; j < n / 2; j++) {
                if (grid[m / 2][j] ^ grid[m / 2][n - 1 - j]) {
                    diff++;
                } else {
                    cnt1 += grid[m / 2][j] * 2;
                }
            }
        }
        if (n & 1) {
            for (int i = 0; i < m / 2; i++) {
                if (grid[i][n / 2] ^ grid[m - 1 - i][n / 2]) {
                    diff++;
                } else {
                    cnt1 += grid[i][n / 2] * 2;
                }
            }
        }
        if (m & 1 && n & 1) {
            ans += grid[m / 2][n / 2];
        }
        if (diff > 0) {
            ans += diff;
        } else {
            ans += cnt1 % 4;
        }
        return ans;
    }
};
