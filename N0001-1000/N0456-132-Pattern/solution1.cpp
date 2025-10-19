class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int leftmin = nums[0];
        multiset<int> rightall;
        for(int i = 2; i < n; i++){
            rightall.insert(nums[i]);
        }
        for(int j = 1; j < n-1; j++){
            if(leftmin < nums[j]){
                auto it = rightall.upper_bound(leftmin);
                if(it != rightall.end() && *it < nums[j]){
                    return true;
                }
            }
            leftmin = min(leftmin, nums[j]);
            rightall.erase(rightall.find(nums[j+1]));
        }
        return false;
    }
};
