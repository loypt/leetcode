class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> seen;
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            seen.insert(nums[i] + nums[j]);
        }
        return seen.size();
    }
};
