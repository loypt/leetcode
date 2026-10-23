class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = (1 << 20) - 1;
        bool any = false;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                ans &= (nums[i] & i);
                any = true;
            }
        }
        return any ? ans : 0;
    }
};
