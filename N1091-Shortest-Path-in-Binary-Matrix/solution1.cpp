class Solution {
public:
    int visited[150][150];
    int move[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(visited, 0, sizeof(visited[0]));
        queue<pair<int, int>> q;
        int ans[n][n];
        
        if(grid[0][0] != 0){
            return -1;
        }
        visited[0][0] = 1;
        q.push(make_pair(0,0));
        ans[0][0] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int next_x = x+move[i][0];
                int next_y = y+move[i][1];
                if(next_x>=0 && next_x<n && next_y>=0 &&next_y<n && grid[next_x][next_y]==0 &&!visited[next_x][next_y]){
                    visited[next_x][next_y] = 1;
                    q.push(make_pair(next_x,next_y));
                    ans[next_x][next_y] = ans[x][y]+1;
                }
            }
        }
        if(visited[n-1][n-1]==0){
            return -1;
        }

        return ans[n-1][n-1];
    }
};
