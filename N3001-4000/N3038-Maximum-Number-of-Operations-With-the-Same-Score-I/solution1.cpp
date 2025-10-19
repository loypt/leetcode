class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size(), t = 0;
        for (int i = 1; i < n; i += 2) {
            if (nums[i] + nums[i - 1] != nums[1] + nums[0]) {
                break;
            }
            t++;
        }
        return t;
    }
};
