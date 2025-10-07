struct Entry {
    int i;
    int j;
    int val;
    bool operator<(const Entry& other) const {
        return this->val > other.val;
    }
    Entry(int ii, int jj, int val): i(ii), j(jj), val(val) {}
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<Entry, vector<Entry>, function<bool(const Entry& x, const Entry& other)>> pq(&Entry::operator<);
        vector<vector<int>> visited(n, vector<int>(n, 0));

        pq.push(Entry(0, 0, grid[0][0]));
        int ret = 0;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            Entry x = pq.top();
            pq.pop();
            if (visited[x.i][x.j] == 1) {
                continue;
            }
            
            visited[x.i][x.j] = 1;
            ret = max(ret, grid[x.i][x.j]);
            if (x.i == n - 1 && x.j == n - 1) {
                break;
            }

            for (const auto [di, dj]: directions) {
                int ni = x.i + di, nj = x.j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    if (visited[ni][nj] == 0) {
                        pq.push(Entry(ni, nj, grid[ni][nj]));
                    }
                }
            }
        }
        return ret;
    }
};
