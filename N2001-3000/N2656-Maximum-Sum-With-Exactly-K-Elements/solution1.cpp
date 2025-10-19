class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m = *max_element(nums.begin(), nums.end());
        return (2 * m + k - 1) * k / 2;
    }
};
