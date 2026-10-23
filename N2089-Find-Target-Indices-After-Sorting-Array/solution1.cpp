class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, eq = 0;
        for (int x : nums) {
            if (x < target) ++less;
            else if (x == target) ++eq;
        }
        vector<int> ans;
        ans.reserve(eq);
        for (int i = 0; i < eq; ++i) ans.push_back(less + i);
        return ans;
    }
};
