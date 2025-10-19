class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<int> min1(26, 1000000001);
        int min2 = 1000000001;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1], j = s[i] - 'a';
            int d = max(abs(x), abs(y));
            if (d < min1[j]) {
                min2 = min(min2, min1[j]);
                min1[j] = d;
            } else if (d < min2) {
                min2 = d;
            }
        }
        int res = 0;
        for (int d : min1) {
            if (d < min2) {
                ++res;
            }
        }
        return res;
    }
};
