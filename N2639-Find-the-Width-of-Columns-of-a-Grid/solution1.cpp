class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> res(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[j] = max(res[j], (int) to_string(grid[i][j]).size());
            }
        }
        return res;
    }
};
