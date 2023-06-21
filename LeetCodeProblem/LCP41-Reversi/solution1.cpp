class Solution {
public:
    const int dirs[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    bool judge(const vector<string>& chessboard, int x, int y, int dx, int dy) {
        x += dx;
        y += dy;
        while (0 <= x && x < chessboard.size() && 0 <= y && y < chessboard[0].size()) {
            if (chessboard[x][y] == 'X') {
                return true;
            } else if (chessboard[x][y] == '.') {
                return false;
            }
            x += dx;
            y += dy;
        }
        return false;
    }

    int bfs(vector<string> chessboard, int px, int py) {
        int cnt = 0;
        queue<pair<int, int>> q;
        q.emplace(px, py);
        chessboard[px][py] = 'X';
        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            for (int i = 0; i < 8; ++i) {
                if (judge(chessboard, t.first, t.second, dirs[i][0], dirs[i][1])) {
                    int x = t.first + dirs[i][0], y = t.second + dirs[i][1];
                    while (chessboard[x][y] != 'X') {
                        q.emplace(x, y);
                        chessboard[x][y] = 'X';
                        x += dirs[i][0];
                        y += dirs[i][1];
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }

    int flipChess(vector<string>& chessboard) {
        int res = 0;
        for (int i = 0; i < chessboard.size(); ++i) {
            for (int j = 0; j < chessboard[0].size(); ++j) {
                if (chessboard[i][j] == '.') {
                    res = max(res, bfs(chessboard, i, j));
                }
            }
        }
        return res;
    }
};
