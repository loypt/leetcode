class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1000000007;
        vector<int> cnt(30, 0);
        for (int x : nums)
            for (int b = 0; b < 30; ++b)
                if (x & (1 << b)) ++cnt[b];
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            long long v = 0;
            for (int b = 0; b < 30; ++b)
                if (cnt[b] > 0) { v |= (1LL << b); --cnt[b]; }
            ans = (ans + v * v) % MOD;
        }
        return (int)ans;
    }
};
