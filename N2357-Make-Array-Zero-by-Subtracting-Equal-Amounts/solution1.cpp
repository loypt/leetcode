class Solution {
public:
    void subtract(vector<int>& nums, int x, int startIndex) {
        int length = nums.size();
        for (int i = startIndex; i < length; i++) {
            nums[i] -= x;
        }
    }

    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (nums[i] > 0) {
                subtract(nums, nums[i], i);
                ans++;
            }
        }
        return ans;
    }
};
