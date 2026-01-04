class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int numOfWays(int n) {
        int fi0 = 6, fi1 = 6;
        for (int i = 2; i <= n; ++i) {
            int new_fi0 = (2LL * fi0 + 2LL * fi1) % mod;
            int new_fi1 = (2LL * fi0 + 3LL * fi1) % mod;
            fi0 = new_fi0;
            fi1 = new_fi1;
        }
        return (fi0 + fi1) % mod;
    }
};
