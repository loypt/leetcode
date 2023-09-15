class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto &operation : operations) {
            int x = operation[0], y = operation[1];
            int number = gem[x] / 2;
            gem[x] -= number;
            gem[y] += number;
        }
        int mn = *min_element(gem.begin(), gem.end());
        int mx = *max_element(gem.begin(), gem.end());
        return mx - mn;
    }
};
