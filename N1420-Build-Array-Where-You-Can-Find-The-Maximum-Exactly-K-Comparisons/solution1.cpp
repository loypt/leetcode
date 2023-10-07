class Solution {
private:
    int f[51][51][101];
    static constexpr int mod = 1000000007;

public:
    int numOfArrays(int n, int m, int k) {
        if (!k) {
            return 0;
        }
        
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= m; ++j) {
            f[1][1][j] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int s = 1; s <= k && s <= i; ++s) {
                for (int j = 1; j <= m; ++j) {
                    f[i][s][j] = (long long)f[i - 1][s][j] * j % mod;
                    for (int j0 = 1; j0 < j; ++j0) {
                        f[i][s][j] += f[i - 1][s - 1][j0];
                        f[i][s][j] %= mod;
                    }
                }
            }
        }

        int ans = 0;
        for (int j = 1; j <= m; ++j) {
            ans += f[n][k][j];
            ans %= mod;
        }
        return ans;
    }
};
