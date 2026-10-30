class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        const int LOG = 17;
        vector<array<int,17>> up(n);
        vector<int> depth(n, 0), tin(n, 0), tout(n, 0), pref(n, 0);
        vector<int> curMask(n, 0);
        for (int i = 0; i < n; i++) curMask[i] = 1 << (s[i] - 'a');
        // BFS for parent / depth / root-prefix xor / binary lifting
        vector<int> par(n, -1);
        par[0] = 0;
        up[0].fill(0);
        depth[0] = 0;
        pref[0] = curMask[0];
        vector<int> bfs; bfs.push_back(0);
        for (size_t bi = 0; bi < bfs.size(); bi++) {
            int u = bfs[bi];
            for (int v : g[u]) if (v != par[u]) {
                par[v] = u;
                depth[v] = depth[u] + 1;
                pref[v] = pref[u] ^ curMask[v];
                up[v][0] = u;
                for (int k = 1; k < LOG; k++) up[v][k] = up[ up[v][k-1] ][k-1];
                bfs.push_back(v);
            }
        }
        // Euler tour: subtree of u is [tin[u], tout[u]]
        int timer = 0;
        struct F2 { int u; size_t i; };
        vector<F2> st;
        st.push_back({0, 0});
        tin[0] = ++timer;
        while (!st.empty()) {
            F2 &fr = st.back();
            int u = fr.u;
            if (fr.i < g[u].size()) {
                int v = g[u][fr.i++];
                if (v == par[u]) continue;
                tin[v] = ++timer;
                st.push_back({v, 0});
            } else {
                tout[u] = timer;
                st.pop_back();
            }
        }
        // Fenwick for range xor update / point query
        int N = n + 2;
        vector<int> bit(N + 2, 0);
        auto bitAdd = [&](int idx, int val) {
            for (; idx <= N; idx += idx & -idx) bit[idx] ^= val;
        };
        auto bitPoint = [&](int idx) {
            int r = 0;
            for (; idx > 0; idx -= idx & -idx) r ^= bit[idx];
            return r;
        };
        auto rangeXor = [&](int l, int r, int val) {
            if (l > r) return;
            bitAdd(l, val);
            bitAdd(r + 1, val);
        };
        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int k = 0; k < LOG; k++) if (diff >> k & 1) a = up[a][k];
            if (a == b) return a;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[a][k] != up[b][k]) { a = up[a][k]; b = up[b][k]; }
            }
            return up[a][0];
        };
        vector<bool> ans;
        ans.reserve(queries.size());
        for (string q : queries) {
            stringstream ss(q);
            string op; ss >> op;
            if (op == "update") {
                int u; char c; ss >> u >> c;
                int nm = 1 << (c - 'a');
                int delta = curMask[u] ^ nm;
                if (delta) {
                    curMask[u] = nm;
                    rangeXor(tin[u], tout[u], delta);
                }
            } else {
                int u, v; ss >> u >> v;
                int w = lca(u, v);
                int pu = pref[u] ^ bitPoint(tin[u]);
                int pv = pref[v] ^ bitPoint(tin[v]);
                int mask = pu ^ pv ^ curMask[w];
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};
