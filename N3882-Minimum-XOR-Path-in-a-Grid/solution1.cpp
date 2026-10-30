class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        dp[0][0].set(grid[0][0]);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                bitset<1024> cur;
                auto add = [&](const bitset<1024>& src) {
                    for (int x = 0; x < 1024; x++) {
                        if (src.test(x)) cur.set(x ^ grid[i][j]);
                    }
                };
                if (i > 0) add(dp[i - 1][j]);
                if (j > 0) add(dp[i][j - 1]);
                dp[i][j] = cur;
            }
        }
        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1].test(x)) return x;
        }
        return -1;
    }
};
