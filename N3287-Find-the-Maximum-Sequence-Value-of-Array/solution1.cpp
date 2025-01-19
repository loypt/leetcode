class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        auto findORs = [&](const vector<int>& nums, int k) -> vector<unordered_set<int>> {
            vector<unordered_set<int>> dp;
            vector<unordered_set<int>> prev(k + 1);
            prev[0].insert(0);
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = min(k - 1, i + 1); j >= 0; --j) {
                    for (int x : prev[j]) {
                        prev[j + 1].insert(x | nums[i]);
                    }
                }
                dp.push_back(prev[k]);
            }
            return dp;
        };

        vector<unordered_set<int>> A = findORs(nums, k);
        vector<unordered_set<int>> B = findORs(vector<int>(nums.rbegin(), nums.rend()), k);
        int mx = 0;
        for (size_t i = k - 1; i < nums.size() - k; ++i) {
            for (int a : A[i]) {
                for (int b : B[nums.size() - i - 2]) {
                    mx = max(mx, a ^ b);
                }
            }
        }
        return mx;
    }
};
