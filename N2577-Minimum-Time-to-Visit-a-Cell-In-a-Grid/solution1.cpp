class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        
        pq.push({grid[0][0], 0, 0});
        while (!pq.empty()) {
            int time = pq.top()[0], row = pq.top()[1], col = pq.top()[2];
            pq.pop();
            
            if (row == m - 1 && col == n - 1) return time;
            
            if (visited[row][col]) continue;
            visited[row][col] = true;
            
            for (auto dr: dirs) {
                int r = row + dr[0], c = col + dr[1];
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c]) continue;
                
                int wait = (grid[r][c] - time) % 2 == 0;
                pq.push({max(grid[r][c] + wait, time + 1), r, c});
            }
        }
        return -1;
    }
};
