class Solution {
public:
    int longestSubarray(vector<int> &nums){
        int x = *max_element(nums.begin(), nums.end());
        int ans = 0, len = 0;
        for (int ele: nums)
        {
            if (ele == x) ans = max(ans, ++len);
            else len = 0;
        }
        return ans;
    }
};
