class Solution {
public:
    int m = 0, n = 0, count = 0;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] != 1) return true;

        grid2[i][j] = 2;
        bool res = true;
        if (grid1[i][j] != 1) res = false;
        for (int k = 0; k < 4; ++k) {
            res = dfs(grid1, grid2, i + dirs[k][0], j + dirs[k][1]) && res;
        }
        return res;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j)) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};
