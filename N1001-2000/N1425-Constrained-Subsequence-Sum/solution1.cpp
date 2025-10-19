class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        deque<int> q;
        q.push_back(0);
        
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            while (!q.empty() && i - q.front() > k) {
                q.pop_front();
            }
            f[i] = max(f[q.front()], 0) + nums[i];
            ans = max(ans, f[i]);
            while (!q.empty() && f[i] >= f[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans;
    }
};
