class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int memo[n][n];

        auto helper = [&](int i, int j, int target) -> int {
            memset(memo, -1, sizeof(memo));
            function<int(int, int)> dfs = [&](int i, int j) -> int {
                if (i >= j) {
                    return 0;
                }
                if (memo[i][j] != -1) {
                    return memo[i][j];
                }
                int ans = 0;
                if (nums[i] + nums[i + 1] == target) {
                    ans = max(ans, 1 + dfs(i + 2, j));
                }
                if (nums[j - 1] + nums[j] == target) {
                    ans = max(ans, 1 + dfs(i, j - 2));
                }
                if (nums[i] + nums[j] == target) {
                    ans = max(ans, 1 + dfs(i + 1, j - 1));
                }
                memo[i][j] = ans;
                return ans;
            };
            return dfs(i, j);
        };

        int res = 0;
        res = max(res, helper(0, n - 1, nums[0] + nums[n - 1]));
        res = max(res, helper(0, n - 1, nums[0] + nums[1]));
        res = max(res, helper(0, n - 1, nums[n - 2] + nums[n - 1]));
        return res;
    }
};
