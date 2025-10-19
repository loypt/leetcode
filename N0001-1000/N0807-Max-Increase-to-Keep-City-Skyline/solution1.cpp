class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowMax(n);
        vector<int> columnMax(n);
        for(int i = 0; i < n; ++i){
            for(int j =0; j < n; ++j){
                rowMax[i] = max(rowMax[i], grid[i][j]);
                columnMax[j] = max(columnMax[j], grid[i][j]);
            }
        }

        int ans = 0;
        for(int i= 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                ans += min(rowMax[i], columnMax[j])-grid[i][j];
            }
        }
        return ans;
    }
};
