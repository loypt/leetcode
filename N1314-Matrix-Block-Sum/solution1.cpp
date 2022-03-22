class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> P(n+1, vector<int>(m+1));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = get(P, n, m, i + k + 1, j + k + 1) - get(P, n, m, i - k, j + k + 1) - get(P, n, m, i + k + 1, j - k) + get(P, n, m, i - k, j - k);
            }
        }
        return ans;
    }

    int get(const vector<vector<int>>& pre, int n, int m, int x, int y){
        x = max(min(x, n), 0);
        y = max(min(y, m), 0);
        return pre[x][y];
    }
};
