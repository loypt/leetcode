class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long> pos(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                pos[i] = (long long) nums[i] - d;
            } else {
                pos[i] = (long long) nums[i] + d;
            }
        }
        sort(pos.begin(), pos.end());
        long long res = 0;
        for (int i = 1; i < n; i++) {
            res += 1ll * (pos[i] - pos[i - 1]) * i % mod * (n - i) % mod;
            res %= mod;
        }
        return res;
    }
};
