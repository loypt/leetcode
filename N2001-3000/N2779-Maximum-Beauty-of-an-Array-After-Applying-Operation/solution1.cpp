class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0, j = 0; i < n; i++) {
            while (nums[i] - 2 * k > nums[j]) {
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
