class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& x : nums) {
            if (x == 2) {
                x = -1;
            } else {
                int t = ~x;
                x ^= (t & -t) >> 1;
            }
        }
        return nums;
    }
};
