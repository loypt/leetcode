class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0){
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            for(int d = 0; d < 4; d++){
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if(ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]){
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }
        return dist;
    }
};
