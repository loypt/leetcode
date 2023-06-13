class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto x : nums) {
            count[x]++;
        }
        int res = 0, n = nums.size(), t = 0;
        for (auto [_, v] : count) {
            res += t * v * (n - t - v);
            t += v;
        }
        return res;
    }
};
