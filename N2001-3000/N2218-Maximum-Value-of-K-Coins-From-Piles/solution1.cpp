class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, 0));
        function<int(int, int)> dp = [&](int i, int l) {
            if (memo[i][l] > 0) return memo[i][l];
            if (i == n || l == 0) return 0;
            int res = dp(i + 1, l), cur = 0;
            for (int j = 0; j < piles[i].size() && j < l; ++j) {
                cur += piles[i][j];
                res = max(res, dp(i + 1, l - j - 1) + cur);
            }
            memo[i][l] = res;
            return res;
        };
        return dp(0, k);
    }
};
