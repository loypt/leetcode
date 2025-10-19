class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int p0 = 0, p1 = 0;
        for (int num: nums) {
            if (num == 0) {
                p1 = p0;
                p0 = 0;
            }
            else {
                ++p0;
                ++p1;
            }
            ans = max(ans, p1);
        }
        if (ans == nums.size()) {
            --ans;
        }
        return ans;
    }
};
