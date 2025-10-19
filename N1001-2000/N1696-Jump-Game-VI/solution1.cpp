class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n, INT_MIN / 2);
        f[0] = nums[0];
        priority_queue<pair<int, int>> heap;
        heap.emplace(nums[0], 0);
        for (int i = 1; i < n; ++i) {
            while (i - heap.top().second > k) {
                heap.pop();
            }
            f[i] = heap.top().first + nums[i];
            heap.emplace(f[i], i);
        }
        return f[n - 1];
    }
};
