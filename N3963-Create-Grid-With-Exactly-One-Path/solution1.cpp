class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> g(m, string(n, '#'));
        for (int j = 0; j < n; j++) g[0][j] = '.';
        for (int i = 0; i < m; i++) g[i][n - 1] = '.';
        return g;
    }
};
