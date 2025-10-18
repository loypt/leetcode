class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int k = 0; k <= n; k++) {
            if (k > 0 && nums[k - 1] >= k) {
                continue;
            }
            if (k < n && nums[k] <= k) {
                continue;
            }
            res++;
        }
        return res;            
    }
};
