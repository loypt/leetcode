class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        double res = numeric_limits<double>::max();
        for (int i = 0; i < n / 2; i++) {
            res = min(res, (nums[i] + nums[n - 1 - i]) / 2.0);
        }
        return res;
    }
};
