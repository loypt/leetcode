class Solution {
public:
    vector<int> zd;

    void build(int l, int r, int rt, vector<int> &heights) {
        if (l == r) {
            zd[rt] = heights[l - 1];
            return;
        }

        int mid = (l + r) >> 1;
        build(l, mid, rt << 1, heights);
        build(mid + 1, r, rt << 1 | 1, heights);
        zd[rt] = max(zd[rt << 1], zd[rt << 1 | 1]);
    }

    int query(int pos, int val, int l, int r, int rt) {
        if (val >= zd[rt]) {
            return 0;
        }

        if (l == r) {
            return l;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) {
            int res = query(pos, val, l, mid, rt << 1);
            if (res != 0) {
                return res;
            }
        }
        return query(pos, val, mid + 1, r, rt << 1 | 1);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        zd.resize(n * 4);
        build(1, n, 1, heights);

        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) {
                swap(a, b);
            }

            if (a == b || heights[a] < heights[b]) {
                ans[i] = b;
                continue;
            }

            ans[i] = query(b + 1, heights[a], 1, n, 1) - 1;
        }
        return ans;
    }
};
