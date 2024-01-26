class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        auto bitCount = [](int x) {
            x = (x & 0b0101010101) + ((x & 0b1010101010) >> 1);
            x = ((x & 0b0011001100) >> 2) + (x & 0b1100110011);
            x = (x >> 8) + ((x >> 4) & 0b1111) + (x & 0b1111);
            return x;
        };

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (bitCount(i) == k) {
                ans += nums[i];
            }
        }
        return ans;
    }
};
