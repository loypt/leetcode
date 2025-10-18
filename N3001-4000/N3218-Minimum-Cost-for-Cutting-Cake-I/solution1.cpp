class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<int> cache(m * m * n * n, -1);
        auto index = [&](int row1, int col1, int row2, int col2) -> int {
            return (row1 * n + col1) * m * n + row2 * n + col2;
        };
        function<int(int, int, int, int)> dp;
        dp = [&](int row1, int col1, int row2, int col2) -> int {
            if (row1 == row2 && col1 == col2) {
                return 0;
            }
            int ind = index(row1, col1, row2, col2);
            if (cache[ind] >= 0) {
                return cache[ind];
            }
            cache[ind] = INT_MAX;
            for (int i = row1; i < row2; i++) {
                cache[ind] = min(cache[ind], dp(row1, col1, i, col2) + dp(i + 1, col1, row2, col2) + horizontalCut[i]);
            }
            for (int i = col1; i < col2; i++) {
                cache[ind] = min(cache[ind], dp(row1, col1, row2, i) + dp(row1, i + 1, row2, col2) + verticalCut[i]);
            }
            return cache[ind];
        };
        return dp(0, 0, m - 1, n - 1);
    }
};
