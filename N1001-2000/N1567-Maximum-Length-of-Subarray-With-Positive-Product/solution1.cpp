class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int positive = (nums[0] > 0);
        int negative = (nums[0] < 0);
        int maxLength = positive;
        for(int i = 1; i < n; ++i){
            if(nums[i] > 0){
                positive++;
                negative = (negative > 0 ? negative + 1 : 0); 
            }else if(nums[i] < 0){
                int newpositive = (negative > 0 ? negative+1 : 0);
                int newnegative = positive+1;
                positive = newpositive;
                negative = newnegative;
            }else{
                positive = 0;
                negative = 0;
            }
            maxLength = max(maxLength, positive);
        }
        return maxLength;
    }
};
