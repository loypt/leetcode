class Solution {
public:
const int pos_x[4] = {0, 0, 1, -1};
const int pos_y[4] = {1, -1, 0, 0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxcnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxcnt = max(maxcnt, dfs(grid, i, j));
            }
        }
        return maxcnt;
    }

    int dfs(vector<vector<int>>& grid, int cur_i, int cur_j){
        if(cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
            return 0;
        }
        grid[cur_i][cur_j] = 0;
        int ans = 1;
        for(int i = 0; i < 4; i++){
            int next_i = cur_i + pos_x[i], next_j = cur_j + pos_y[i];
            ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }
};
