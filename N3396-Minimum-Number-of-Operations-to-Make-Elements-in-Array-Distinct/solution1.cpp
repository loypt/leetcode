class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        auto checkUnique = [&](int start) {
            unordered_set<int> seen;
            for (int i = start; i < nums.size(); i++) {
                if (seen.count(nums[i])) {
                    return false;
                }
                seen.emplace(nums[i]);
            }
            return true;
        };

        int ans = 0;
        for (int i = 0; i < nums.size(); i += 3, ans++) {
            if (checkUnique(i)) {
                return ans;
            }
        }
        return ans;
    }
};
