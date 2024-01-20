class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<int> dp(n + 1, 0);
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = {nums2[i], nums1[i]};
        }
        sort(nums.begin(), nums.end());

        for (int j = 1; j <= n; j++) {
            int b = nums[j - 1].first, a = nums[j - 1].second;
            for (int i = j; i > 0; i--) {
                dp[i] = max(dp[i], dp[i - 1] + i * b + a);
            }
        }

        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int i = 0; i <= n; i++) {
            if (s2 * i + s1 - dp[i] <= x) {
                return i;
            }
        }
        return -1;
    }
};
