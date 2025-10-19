class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> g(26, 0);
        int n = s.size(), total = 0;
        for (int i = 0; i < n; ++i) {
            int oi = s[i] - 'a';
            int prev = g[oi];
            g[oi] = (total + 1) % mod;
            total = ((total + g[oi] - prev) % mod + mod) % mod;
        }
        return total;
    }

private:
    static constexpr int mod = 1000000007;
};
