class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size(), m = andValues.size();
        memo.resize(m * n);
        int res = dfs(0, 0, INF, nums, andValues);
        return res < INF ? res : -1;
    }

private:
    static const int INF = (1 << 20) - 1;
    vector<unordered_map<int, int>> memo;
    int dfs(int i, int j, int cur, vector<int>& nums, vector<int>& andValues) {
        int n = nums.size(), m = andValues.size(), key = i * m + j;
        if (i == n && j == m) return 0;
        if (i == n || j == m) return INF;
        if (memo[key].count(cur)) return memo[key][cur];

        cur &= nums[i];
        if ((cur & andValues[j]) < andValues[j]) return INF;

        int res = dfs(i + 1, j, cur, nums, andValues);
        if (cur == andValues[j]) {
            res = min(res, dfs(i + 1, j + 1, INF, nums, andValues) + nums[i]);
        }
        memo[key][cur] = res;
        return res;
    }
};
