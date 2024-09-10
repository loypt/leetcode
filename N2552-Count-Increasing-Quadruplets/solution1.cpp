class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1);
        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            int suf = 0;
            for (int k = n - 1; k > j; --k) {
                if (nums[j] > nums[k]) {
                    ans += static_cast<long long>(pre[nums[k]]) * suf;
                }
                else {
                    ++suf;
                }
            }
            for (int x = nums[j] + 1; x <= n; ++x) {
                ++pre[x];
            }
        }
        return ans;
    }
};
