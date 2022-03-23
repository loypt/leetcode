class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while(startValue < target){
            ans++;
            if((target & 1) == 1){
                target++;
            }else{
                target /= 2;
            }
        }
        return ans + startValue - target;
    }
};
