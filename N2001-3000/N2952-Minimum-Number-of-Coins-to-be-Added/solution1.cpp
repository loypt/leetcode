class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        int x = 1;
        int length = coins.size(), index = 0;
        while (x <= target) {
            if (index < length && coins[index] <= x) {
                x += coins[index];
                index++;
            } else {
                x <<= 1;
                ans++;
            }
        }
        return ans;
    }
};
