class Solution {
public:
    using ll = long long;
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> suf(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] | nums[i];
        }

        ll res = 0;
        ll pre = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, pre | (1ll * nums[i] << k) | suf[i + 1]);
            pre |= nums[i];
        }
        return res;
    }
};
