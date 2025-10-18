class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        int maxVar = INT_MIN;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j < i; ++j){
                maxVar = max(maxVar, max(j*(i-j), j*dp[i-j]));
            }
            dp[i] = maxVar;
        }

        return dp[n];
    }
};
