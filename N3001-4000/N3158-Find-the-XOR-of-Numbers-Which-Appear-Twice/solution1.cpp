class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> cnt;
        int res = 0;
        for (int num : nums) {
            if (cnt.find(num) != cnt.end()) {
                res ^= num;
            } else {
                cnt.emplace(num);
            }
        }
        return res;
    }
};
