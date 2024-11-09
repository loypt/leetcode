class Solution {
public:
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        vector<bool> visited(circles.size(), false);

        function<bool(int)> dfs = [&](int i) -> bool {
            int x1 = circles[i][0], y1 = circles[i][1], r1 = circles[i][2];
            if (circleIntersectsBottomRightOfRectangle(x1, y1, r1, xCorner, yCorner)) {
                return true;
            }
            visited[i] = true;
            for (int j = 0; j < circles.size(); ++j) {
                int x2 = circles[j][0], y2 = circles[j][1], r2 = circles[j][2];
                if (!visited[j] && circlesIntersectInRectangle(x1, y1, r1, x2, y2, r2, xCorner, yCorner) && dfs(j)) {
                    return true;
                }
            }
            return false;
        };

        for (int i = 0; i < circles.size(); ++i) {
            int x = circles[i][0], y = circles[i][1], r = circles[i][2];
            if (pointInCircle(0, 0, x, y, r) || pointInCircle(xCorner, yCorner, x, y, r)) {
                return false;
            }
            if (!visited[i] && circleIntersectsTopLeftOfRectangle(x, y, r, xCorner, yCorner) && dfs(i)) {
                return false;
            }
        }
        return true;
    }

    bool pointInCircle(long long px, long long py, long long x, long long y, long long r) {
        return (x - px) * (x - px) + (y - py) * (y - py) <= (long long)r * r;
    }

    bool circleIntersectsTopLeftOfRectangle(int x, int y, int r, int xCorner, int yCorner) {
        return (abs(x) <= r && 0 <= y && y <= yCorner) ||
            (0 <= x && x <= xCorner && abs(y - yCorner) <= r) ||
            pointInCircle(x, y, 0, yCorner, r);
    }

    bool circleIntersectsBottomRightOfRectangle(int x, int y, int r, int xCorner, int yCorner) {
        return (abs(y) <= r && 0 <= x && x <= xCorner) ||
            (0 <= y && y <= yCorner && abs(x - xCorner) <= r) ||
            pointInCircle(x, y, xCorner, 0, r);
    }

    bool circlesIntersectInRectangle(long long x1, long long y1, long long r1, long long x2, long long y2, long long r2, long long xCorner, long long yCorner) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2) &&
            x1 * r2 + x2 * r1 < (r1 + r2) * xCorner &&
            y1 * r2 + y2 * r1 < (r1 + r2) * yCorner;
    }
};
