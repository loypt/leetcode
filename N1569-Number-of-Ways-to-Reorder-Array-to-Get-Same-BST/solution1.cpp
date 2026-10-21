// 1569. Number of Ways to Reorder Array to Get Same BST
class Solution {
public:
    static constexpr int MOD = 1000000007;
    vector<vector<long long>> C;

    int numOfWays(vector<int>& nums) {
        int n = (int)nums.size();
        C.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
        return (int)((dfs(nums) + MOD - 1) % MOD);
    }

    long long dfs(const vector<int>& a) {
        int n = (int)a.size();
        if (n <= 2) return 1;
        vector<int> L, R;
        L.reserve(n); R.reserve(n);
        for (int i = 1; i < n; i++) {
            if (a[i] < a[0]) L.push_back(a[i]);
            else R.push_back(a[i]);
        }
        return C[L.size() + R.size()][L.size()] * dfs(L) % MOD * dfs(R) % MOD;
    }
};
