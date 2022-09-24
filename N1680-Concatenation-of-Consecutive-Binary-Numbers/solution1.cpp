class Solution {
public:
    int concatenatedBinary(int n) {
        int ans = 0;
        int shift = 0;
        for (int i = 1; i <= n; ++i) {
            if (!(i & (i - 1))) {
                ++shift;
            }
            ans = ((static_cast<long long>(ans) << shift) + i) % mod;
        }
        return ans;
    }
private:
    static constexpr int mod = 1000000007;
};
