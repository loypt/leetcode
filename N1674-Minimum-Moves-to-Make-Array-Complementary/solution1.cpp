class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);

            diff[2] += 2;
            diff[a + 1] -= 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
            diff[b + limit + 1] += 1;
        }

        int min_ops = n;
        int current_ops = 0;

        for (int c = 2; c <= 2 * limit; ++c) {
            current_ops += diff[c];
            min_ops = min(min_ops, current_ops);
        }

        return min_ops;
    }
};
