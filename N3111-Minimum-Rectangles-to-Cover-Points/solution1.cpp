class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int res = 0;
        int bound = -1;
        for (auto &p : points) {
            if (p[0] > bound) {
                bound = p[0] + w;
                res++;
            }
        }
        return res;
    }
};
