class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> isrestricted(n);
        for (auto x : restricted) {
            isrestricted[x] = 1;
        }

        vector<vector<int>> g(n);
        for (auto &v : edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        int cnt = 0;
        function<void(int, int)> dfs = [&](int x, int f) {
            cnt++;
            for (auto &y : g[x]) {
                if (y != f && !isrestricted[y]) {
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);
        return cnt;
    }
};
