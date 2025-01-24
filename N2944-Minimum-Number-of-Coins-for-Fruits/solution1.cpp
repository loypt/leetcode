class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int index) -> int {
            if (2 * index + 2 >= prices.size()) {
                return prices[index];
            }
            if (!memo.count(index)) {
                int minValue = INT_MAX;
                for (int i = index + 1; i <= 2 * index + 2; i++) {
                    minValue = min(minValue, dp(i));
                }
                memo[index] = prices[index] + minValue;
            }
            return memo[index];
        };

        return dp(0);
    }
};
