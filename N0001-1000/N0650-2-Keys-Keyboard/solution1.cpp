class Solution {
public:
    int minSteps(int n) {
        vector<int> f(n + 1);
        for (int i = 2; i <= n; ++i) {
            f[i] = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    f[i] = min(f[i], f[j] + i / j);
                    f[i] = min(f[i], f[i / j] + j);
                }
            }
        }
        return f[n];
    }
};
