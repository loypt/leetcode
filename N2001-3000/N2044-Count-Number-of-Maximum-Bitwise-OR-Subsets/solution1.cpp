class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), cnt = 0, maxValue = 0, state =  1 << n;
        for(int i = 1; i < state; i++){
            int cur = 0; 
            for(int j = 0; j < n; j++){
                if(((i >> j ) & 1) == 1){
                    cur |= nums[j];
                }
            }
            if(cur > maxValue){
                maxValue = cur;
                cnt=1;
            }else if(cur == maxValue){
                cnt++;
            }
        }
        return cnt;
    }
};
