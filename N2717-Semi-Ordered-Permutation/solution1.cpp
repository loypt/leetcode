class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        auto [first, last] = minmax_element(nums.begin(), nums.end());
        return first + nums.size() - 1 - last - (last < first);
    }
};
