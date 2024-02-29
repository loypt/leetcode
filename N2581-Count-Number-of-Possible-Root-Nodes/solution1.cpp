class Solution {
public:
    using ll = long long;
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        unordered_set<ll> st;
        for (auto &v : edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        auto h = [&](int x, int y) -> ll {
            return (ll) x << 20 | y;
        };
        for (auto &v : guesses) {
            st.insert(h(v[0], v[1]));
        }

        int cnt = 0, res = 0;
        function<void(int, int)> dfs = [&](int x, int fat) -> void {
            for (auto &y : g[x]) {
                if (y == fat) {
                    continue;
                }
                cnt += st.count(h(x, y));
                dfs(y, x);
            }
        };
        dfs(0, -1);

        function<void(int, int, int)> redfs = [&](int x, int fat, int cnt) {
            if (cnt >= k) {
                res++;
            }
            for (auto &y : g[x]) {
                if (y == fat) {
                    continue;
                }
                redfs(y, x, cnt - st.count(h(x, y)) + st.count(h(y, x)));
            }
        };
        redfs(0, -1, cnt);
        return res;
    }
};
