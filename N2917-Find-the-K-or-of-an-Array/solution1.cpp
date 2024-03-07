class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int cnt = 0;
            for (int num: nums) {
                if ((num >> i) & 1) {
                    ++cnt;
                }
            }
            if (cnt >= k) {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};
