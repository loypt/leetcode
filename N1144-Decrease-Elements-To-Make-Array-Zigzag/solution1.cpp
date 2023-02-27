class Solution {
public:
    int help(vector<int>& nums, int pos) {
        int res = 0;
        for (int i = pos; i < nums.size(); i += 2) {
            int a = 0;
            if (i - 1 >= 0) {
                a = max(a, nums[i] - nums[i - 1] + 1);
            }
            if (i + 1 < nums.size()) {
                a = max(a, nums[i] - nums[i + 1] + 1);
            }
            res += a;
        }
        return res;
    }

    int movesToMakeZigzag(vector<int>& nums) {
        return min(help(nums, 0), help(nums, 1));
    }
};
