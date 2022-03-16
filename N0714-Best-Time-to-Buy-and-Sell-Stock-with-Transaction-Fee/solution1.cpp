class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp1 = 0, dp2 = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            tie(dp1, dp2) = pair(max(dp1, dp2+prices[i]-fee), max(dp2, dp1-prices[i]));
        }
        return dp1;
    }
};
