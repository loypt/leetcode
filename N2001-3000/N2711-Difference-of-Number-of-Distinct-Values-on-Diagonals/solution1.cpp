class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                set<int> s1;
                int x = i + 1, y = j + 1;
                while (x < m && y < n) {
                    s1.insert(grid[x][y]);
                    x += 1;
                    y += 1;
                }
                set<int> s2;
                x = i - 1, y = j - 1;
                while (x >= 0 && y >= 0) {
                    s2.insert(grid[x][y]);
                    x -= 1;
                    y -= 1;
                }
                res[i][j] = abs((int)s1.size() - (int)s2.size());
            }
        }
        return res;
    }
};
