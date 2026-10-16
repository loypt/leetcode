class Solution {
public:
    static const int MOD = 1000000007;
    struct BIT {
        int n;
        vector<long long> t;
        BIT() {}
        BIT(int n): n(n), t(n + 1, 0) {}
        void add(int i, long long v) { for (++i; i <= n; i += i & -i) t[i] += v; }
        long long sum(int i) { long long s = 0; for (++i; i > 0; i -= i & -i) s += t[i]; return s; }
    };
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        BIT b1(n), b2(n);
        auto range_add = [&](int l, int r, long long v) {
            if (l > r) return;
            b1.add(l, v); if (r + 1 < n) b1.add(r + 1, -v);
            b2.add(l, v * l); if (r + 1 < n) b2.add(r + 1, -v * (r + 1));
        };
        auto prefix = [&](int i) -> long long {
            if (i < 0) return 0;
            return b1.sum(i) * (i + 1) - b2.sum(i);
        };
        auto range_sum = [&](int l, int r) -> long long {
            if (l > r) return 0;
            return prefix(r) - prefix(l - 1);
        };
        vector<int> last(100001, -1);
        long long f = 0, ans = 0;
        for (int r = 0; r < n; ++r) {
            int p = last[nums[r]];
            long long S = range_sum(p + 1, r - 1) % MOD;
            f = (f + 2 * S % MOD + (r - p)) % MOD;
            range_add(p + 1, r, 1);
            last[nums[r]] = r;
            ans = (ans + f) % MOD;
        }
        return (int)ans;
    }
};
