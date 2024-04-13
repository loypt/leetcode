class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            if (accumulate(grid[i].begin(), grid[i].end(), 0) == n - 1) {
                return i;
            }
        }
        return -1;
    }
};
