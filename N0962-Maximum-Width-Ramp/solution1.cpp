class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            if (s.empty() || nums[s.top()] > nums[i])
                s.push(i);
        for (int i = n - 1; i > res; --i)
            while (!s.empty() && nums[s.top()] <= nums[i])
                res = max(res, i - s.top()), s.pop();
        return res;
    }
};
