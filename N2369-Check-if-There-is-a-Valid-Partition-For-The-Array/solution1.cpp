class Solution {
public:
    bool validPartition(vector<int> &nums) {
        int n = nums.size();
        bool f[n + 1]; memset(f, 0, sizeof(f));
        f[0] = true;
        for (int i = 1; i < n; ++i)
            if (f[i - 1] && nums[i] == nums[i - 1] ||
                i > 1 && f[i - 2] && (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] ||
                                      nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2))
                f[i + 1] = true;
        return f[n];
    }
};
