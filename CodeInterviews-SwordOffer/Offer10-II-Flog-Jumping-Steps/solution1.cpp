class Solution {
public:
    int numWays(int n) {
        if(n == 0 && n==1){
            return 1;
        }
        int dp1 = 1, dp2 = 1;
        for(int i = 0; i < n; i++){
            int temp = (dp1 + dp2)%1000000007;
            dp1 = dp2;
            dp2 = temp;
        }
        return dp1;
    }
};
