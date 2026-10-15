class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int cnt[101] = {0};
            int distinct = 0;
            for (int j = i; j < n; ++j) {
                if (cnt[nums[j]] == 0) ++distinct;
                ++cnt[nums[j]];
                ans += distinct * distinct;
            }
        }
        return ans;
    }
};
