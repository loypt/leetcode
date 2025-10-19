class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int mx1 = max(nums[0], nums[1]);
        int mx2 = min(nums[0], nums[1]);
        int mn1 = min(nums[0], nums[1]);
        int mn2 = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i){
            int tmp = nums[i];
            if (tmp > mx1){
                mx2 = mx1;
                mx1 = tmp;
            }
            else if (tmp > mx2){
                mx2 = tmp;
            }
            if (tmp < mn1){
                mn2 = mn1;
                mn1 = tmp;
            }
            else if (tmp < mn2){
                mn2 = tmp;
            }
        }
        return (mx1 * mx2) - (mn1 * mn2);
    }
};
