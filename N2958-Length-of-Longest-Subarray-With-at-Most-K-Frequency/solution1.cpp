class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int res = 0, i = 0, n = nums.size();
        for (int j = 0; j < n; ++j) {   
            count[nums[j]]++;
            while (count[nums[j]] > k)
                count[nums[i++]]--;
            res = max(res, j - i + 1);
        }
        return res;
    }
};
