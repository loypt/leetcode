class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool check = true;
        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i] == nums[i + 1] && check) {
                ++ans;
            }
            else {
                check = !check;
            }
        }
        if ((n - ans) % 2 != 0) {
            ++ans;
        }
        return ans;
    }
};
