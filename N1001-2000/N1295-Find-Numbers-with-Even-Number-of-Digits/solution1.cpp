class Solution {
public:
    int findNumbers(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](int ans, int num) {
            return ans + (to_string(num).size() % 2 == 0);
        });
    }
};
