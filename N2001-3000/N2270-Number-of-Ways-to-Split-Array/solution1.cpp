class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long left = 0, right = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            left += nums[i];
            right -= nums[i];
            if (left >= right) {
                ++ans;
            }
        }
        return ans;
    }
};
