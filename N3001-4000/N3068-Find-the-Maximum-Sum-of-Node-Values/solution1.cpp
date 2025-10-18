class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;
        int d = 1 << 30, c = 0;
        for (int num : nums) {
            int b = num ^ k;
            res += max(num, b);
            c ^= num < b;
            d = min(d, abs(num - b));
        }
        return res - d * c;
    }
};
