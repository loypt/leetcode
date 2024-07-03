class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int ret = 2e9;
        for (int i = 0; i < 4; i++) {
            ret = min(ret, nums[n - 4 + i] - nums[i]);
        }
        return ret;
    }
};
