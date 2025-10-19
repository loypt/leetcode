class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        const int n = nums.size(), m = n/k;
        const vector<int> bmap = getMap(nums, m);

        vector<int> dp(1<<n, -1);
        dp[0] = 0;
        for (int b = 0; b < (1<<n); ++b) {
            if (__builtin_popcount(b) % m != 0) continue;
            for (int tb = b; tb; tb = (tb-1)&b) {
                if (bmap[tb] == -1) continue;
                if (dp[b-tb] == -1) continue;
                if (dp[b] == -1) dp[b] = dp[b-tb]+bmap[tb];
                else dp[b] = min(dp[b], dp[b-tb]+bmap[tb]);
            }
        }
        return dp.back();
    }

private:
    vector<int> getMap(const vector<int>& nums, int m) {
	    const int n = nums.size();
        vector<int> ans(1<<n, -1);
        for (int b = 0; b < (1<<n); ++b) {
            if (__builtin_popcount(b) != m) continue;

            int vis = 0;
            int mx = 0, mn = 16;
            bool is_good = true;
            for (int i = 0; i < n; ++i) {
                if ((b & (1<<i)) == 0) continue;
                if (vis & (1<<nums[i])) {
                    is_good = false;
                    break;
                }
                vis |= (1<<nums[i]);
                mx = max(mx, nums[i]);
                mn = min(mn, nums[i]);
            }
            if (!is_good) continue;
            
            ans[b] = mx-mn;
        }
        return ans;
    }
};
