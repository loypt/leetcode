class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        vector<long long> A = {0};
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                A.push_back(A.back() + i);
        int n = A.size() - 1, m = max(0, k - maxChanges);
        long long res = 1e10;
        for (int l = m; l <= min(n, min(m + 3, k)); ++l) {
            for (int i = 0; i <= n - l; ++i) {
                int mid1 = i + l / 2, mid2 = i + l - l / 2;
                long long cur = A[i + l] - A[mid2] - (A[mid1] - A[i]);
                res = min(res, cur + (k - l) * 2);
            }
        }
        return res;
    }
};
