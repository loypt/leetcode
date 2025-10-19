class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        int sum = 0, two = 0;
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                ++two;
            }
            sum += colsum[i];
        }
        if (sum != upper + lower || min(upper, lower) < two) {
            return {};
        }
        upper -= two;
        lower -= two;
        vector<vector<int>> res(2, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                res[0][i] = res[1][i] = 1;
            } else if (colsum[i] == 1) {
                if (upper > 0) {
                    res[0][i] = 1;
                    --upper;
                } else {
                    res[1][i] = 1;
                }
            }
        }
        return res;
    }
};
