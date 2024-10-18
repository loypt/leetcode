class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (i > n - 3) {
                    return -1;
                }
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ans++;
            }
        }

        return ans;
    }
};
