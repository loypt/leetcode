class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        long n = nums.size() + 2;
        int a = -accumulate(nums.cbegin(), nums.cend(), -(1 + n) * n / 2);
        int b = -inner_product(nums.cbegin(), nums.cend(), nums.cbegin(), -(1 + n) * n / 2 * (2 * n + 1) / 3);
        int tmp = sqrt(2 * b - a * a);
        return { (a + tmp) / 2, (a - tmp) / 2 };
    }
};