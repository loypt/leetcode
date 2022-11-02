class Solution {
public:
    vector<int> findBall(vector<vector<int>> &grid) {
        int n = grid[0].size();
        vector<int> ans(n);
        for (int j = 0; j < n; ++j) {
            int col = j; 
            for (auto &row : grid) {
                int dir = row[col];
                col += dir;
                if (col < 0 || col == n || row[col] != dir) {
                    col = -1;
                    break;
                }
            }
            ans[j] = col;
        }
        return ans;
    }
};
