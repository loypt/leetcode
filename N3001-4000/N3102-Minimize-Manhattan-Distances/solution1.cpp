class Solution {
public:
    int remove(vector<pair<int, int>> &arr, int i) {
        int n = arr.size();
        if (arr[0].second == i) {
            return arr[n - 1].first - arr[1].first;
        } else if (arr.back().second == i) {
            return arr[n - 2].first - arr[0].first;
        } else {
            return arr[n - 1].first - arr[0].first;
        }
    }
    
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> sx, sy;
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            sx.emplace_back(x - y, i);
            sy.emplace_back(x + y, i);
        }
        sort(sx.begin(), sx.end());
        sort(sy.begin(), sy.end());
        int maxVal1 = sx.back().first - sx[0].first;
        int maxVal2 = sy.back().first - sy[0].first;
        int res = INT_MAX;
        if (maxVal1 >= maxVal2) {
            int i = sx[0].second, j = sx.back().second;
            res = min(res, max(remove(sx, i), remove(sy, i)));
            res = min(res, max(remove(sx, j), remove(sy, j)));
        } else {
            int i = sy[0].second, j = sy.back().second;
            res = min(res, max(remove(sx, i), remove(sy, i)));
            res = min(res, max(remove(sx, j), remove(sy, j)));
        }
        
        return res;
    }
};
