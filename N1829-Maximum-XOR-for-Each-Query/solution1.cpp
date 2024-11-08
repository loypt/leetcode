class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int mask = (1 << maximumBit) - 1;
        int xorsum = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        
        vector<int> ans;
        for (int i = n - 1; i >= 0; --i) {
            ans.push_back(xorsum ^ mask);
            xorsum ^= nums[i];
        }
        return ans;
    }
};
