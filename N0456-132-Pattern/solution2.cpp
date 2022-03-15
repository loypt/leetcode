class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        stk.push(nums[n-1]);
        int max_k = INT_MIN;
        for(int i = n-2; i >= 0; --i){
            // 1 min value
            if(nums[i] < max_k){
                return true;
            }
            // 2
            while(!stk.empty() && nums[i] > stk.top()){
                max_k = stk.top();
                stk.pop();
            }
            // 3 the max value
            if(nums[i] > max_k){
                stk.push(nums[i]);
            }
        }
        return false;
    }
};
