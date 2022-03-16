class Solution {
    int cnt = 0;
    int dis[10][10];
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int ,int>> que;
        memset(dis, -1, sizeof(dis));
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 2){
                    que.push(make_pair(i, j));
                    dis[i][j] = 0;
                }else if(grid[i][j] == 1){
                    cnt += 1;
                }
            }
        }
        while(!que.empty()){
            pair<int ,int> x = que.front();
            que.pop();
            for(int i = 0; i < 4; i++){
                int nx = x.first + dirs[i][0];
                int ny = x.second + dirs[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || ~dis[nx][ny] || !grid[nx][ny]) continue;
                dis[nx][ny] = dis[x.first][x.second] + 1;
                que.push(make_pair(nx, ny));
                if(grid[nx][ny] == 1){
                    cnt -= 1;
                    ans = dis[nx][ny];
                    if(!cnt) break;
                }
            }
        }
        return cnt ? -1 : ans;

    }
};
