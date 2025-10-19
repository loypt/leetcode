class Solution {
public:
    int minOperations(vector<int>& nums) {
        int pre = nums[0] - 1, res = 0;
        for (int num : nums) {
            pre = max(pre + 1, num);
            res += pre - num;
        }
        return res;
    }
};
