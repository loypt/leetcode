class Solution {
    vector<int> &nums;
public:
    Solution(vector<int>& nums) : nums(nums) {}
    
    int pick(int target) {
        int ans;
        for(int i = 0, cnt = 0; i < nums.size(); ++i){
            if(nums[i] == target){
                cnt++;
                if(rand() % cnt == 0){
                    ans = i;
                }
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
