class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int rowCnt = 0, colCnt = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j1 = 0, j2 = n - 1; j1 < j2; j1++, j2--) {
                if (grid[i][j1] ^ grid[i][j2]) {
                    rowCnt++;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i1 = 0, i2 = m - 1; i1 < i2; i1++, i2--) {
                if (grid[i1][j] ^ grid[i2][j]) {
                    colCnt++;
                }
            }
        }
        return min(colCnt, rowCnt);
    }
};
