class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        function<int(int, int)> dfs = [&](int x, int y) -> int {
            if (x < 0 || x >= m || y < 0 || y >= n || land[x][y] != 0) {
                return 0;
            }
            land[x][y] = -1;
            int res = 1;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    res += dfs(x + dx, y + dy);
                }
            }
            return res;
        };

        vector<int> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0) {
                    res.push_back(dfs(i, j));
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
