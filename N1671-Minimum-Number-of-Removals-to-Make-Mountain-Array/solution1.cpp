class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre = getLISArray(nums);
        vector<int> suf = getLISArray({nums.rbegin(), nums.rend()});
        reverse(suf.begin(), suf.end());

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (pre[i] > 1 && suf[i] > 1) {
                ans = max(ans, pre[i] + suf[i] - 1);
            }
        }

        return n - ans;
    }

    vector<int> getLISArray(const vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n), seq;
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
            if (it == seq.end()) {
                seq.push_back(nums[i]);
                dp[i] = seq.size();
            }
            else {
                *it = nums[i];
                dp[i] = it - seq.begin() + 1;
            }
        }
        return dp;
    }
};
