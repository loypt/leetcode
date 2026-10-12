class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        int mx = 0;
        for (int i = 0; i < n; i++) mx = max(mx, abs(nums1[i] - nums2[i]));
        vector<long long> cnt(mx + 1, 0);
        for (int i = 0; i < n; i++) cnt[abs(nums1[i] - nums2[i])]++;
        for (int d = mx; d > 0 && k > 0; d--) {
            long long take = min(cnt[d], k);
            cnt[d] -= take;
            cnt[d - 1] += take;
            k -= take;
        }
        long long ans = 0;
        for (int d = 1; d <= mx; d++) ans += 1LL * d * d * cnt[d];
        return ans;
    }
};
