class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int res = 1;
        sort(coins.begin(), coins.end());
        for (auto& i : coins) {
            if (i > res) {
                break;
            }
            res += i;
        }
        return res;
    }
};
