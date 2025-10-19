class Solution {
    vector<vector<int>> rotate(const vector<vector<int>> a) {
        int m = a.size(), n = a[0].size();
        vector b(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                b[j][m - 1 - i] = a[i][j];
            }
        }
        return b;
    }

    vector<vector<int>> minimumArea(const vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector f(m + 1, vector<int>(n + 1));
        vector<tuple<int, int, int>> border(n + 1, {-1, -1, -1});
        for (int i = 0; i < m; i++) {
            int left = -1, right = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j]) {
                    if (left < 0) {
                        left = j;
                    }
                    right = j;
                }
                auto& [pre_top, pre_left, pre_right] = border[j];
                if (left < 0) {
                    f[i + 1][j + 1] = f[i][j + 1];
                } else if (pre_top < 0) {
                    f[i + 1][j + 1] = right - left + 1;
                    border[j] = {i, left, right};
                } else {
                    int l = min(pre_left, left), r = max(pre_right, right);
                    f[i + 1][j + 1] = (r - l + 1) * (i - pre_top + 1);
                    border[j] = {pre_top, l, r};
                }
            }
        }
        return f;
    }

    int solve(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        
        vector<pair<int, int>> lr(m);
        for (int i = 0; i < m; i++) {
            int l = -1, r = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] > 0) {
                    if (l < 0) {
                        l = j;
                    }
                    r = j;
                }
            }
            lr[i] = {l, r};
        }

        vector<vector<int>> lt = minimumArea(a);
        a = rotate(a);
        vector<vector<int>> lb = rotate(rotate(rotate(minimumArea(a))));
        a = rotate(a);
        vector<vector<int>> rb = rotate(rotate(minimumArea(a)));
        a = rotate(a);
        vector<vector<int>> rt = rotate(minimumArea(a));

        int ans = INT_MAX;
        if (m >= 3) {
            for (int i = 1; i < m; i++) {
                int left = n, right = 0, top = m, bottom = 0;
                for (int j = i + 1; j < m; j++) {
                    if (auto& [l, r] = lr[j - 1]; l >= 0) {
                        left = min(left, l);
                        right = max(right, r);
                        top = min(top, j - 1);
                        bottom = j - 1;
                    }
                    ans = min(ans, lt[i][n] + (right - left + 1) * (bottom - top + 1) + lb[j][n]);
                }
            }
        }

        if (m >= 2 && n >= 2) {
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    ans = min(ans, lt[i][n] + lb[i][j] + rb[i][j]);
                    ans = min(ans, lt[i][j] + rt[i][j] + lb[i][n]);
                }
            }
        }
        return ans;
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        auto a = rotate(grid);
        return min(solve(grid), solve(a));
    }
};
