class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        unordered_set<int> primes = {
            2, 3, 5, 7, 11,
            13, 17, 19, 23, 29,
            31, 37, 41, 43, 47,
            53, 59, 61, 67, 71,
            73, 79, 83, 89, 97
        };

        int n = nums.size();
        int first = -1, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (primes.count(nums[i])) {
                if (first != -1) {
                    ans = max(ans, i - first);
                }
                else {
                    first = i;
                }
            }
        }
        return ans;
    }
};
