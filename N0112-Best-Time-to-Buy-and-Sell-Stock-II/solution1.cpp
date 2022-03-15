class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp0 = 0, dp1 = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            int newdp0 = max(dp1+prices[i], dp0);
            int newdp1 = max(dp0-prices[i], dp1);
            dp0 = newdp0;
            dp1 = newdp1;
        }
        return dp0;
    }
};
