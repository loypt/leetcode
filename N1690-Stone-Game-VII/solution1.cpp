class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sum(n + 1);
        vector<vector<int>> memo(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + stones[i];
        }

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i >= j) {
                return 0;
            }
            if (memo[i][j] != 0) {
                return memo[i][j];
            }
            int res = max(sum[j + 1] - sum[i + 1] - dfs(i + 1, j), sum[j] - sum[i] - dfs(i, j - 1));
            memo[i][j] = res;
            return res;
        };
        return dfs(0, n - 1);
    }
};
