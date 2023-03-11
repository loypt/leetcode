class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int x = 0;
        for (auto num : nums) {
            x = (x + num) % p;
        }
        if (x == 0) {
            return 0;
        }
        unordered_map<int, int> index;
        int y = 0, res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            index[y] = i;
            y = (y + nums[i]) % p;
            if (index.count((y - x + p) % p) > 0) {
                res = min(res, i - index[(y - x + p) % p] + 1);
            }
        }
        return res == nums.size() ? -1 : res;
    }
};
