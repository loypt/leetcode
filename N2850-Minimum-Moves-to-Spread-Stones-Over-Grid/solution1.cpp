class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> more, less;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] > 1) {
                    for (int k = 2; k <= grid[i][j]; ++k) {
                        more.emplace_back(i, j);
                    }
                }
                else if (grid[i][j] == 0) {
                    less.emplace_back(i, j);
                }
            }
        }

        int ans = INT_MAX;
        do {
            int steps = 0;
            for (int i = 0; i < more.size(); ++i) {
                steps += abs(more[i].first - less[i].first) + abs(more[i].second - less[i].second);
            }
            ans = min(ans, steps);
        } while (next_permutation(more.begin(), more.end()));
        return ans;
    }
};
