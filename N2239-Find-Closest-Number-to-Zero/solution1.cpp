class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = nums[0];
        int dis = abs(nums[0]);
        for (int num: nums) {
            if (abs(num) < dis) {
                dis = abs(num);
                res = num;
            } else if (abs(num) == dis) {
                res = max(res, num);
            }
        }
        return res;
    }
};
