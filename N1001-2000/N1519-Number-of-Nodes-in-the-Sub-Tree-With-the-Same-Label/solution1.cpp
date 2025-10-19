class Solution {
public:
    vector<vector<int>> g;
    vector<vector<int>> f; 
    
    void dfs(int o, int pre, const string &labels) {
        f[o][labels[o] - 'a'] = 1;
        for (const auto &nex: g[o]) {
            if (nex == pre) {
                continue;
            } 
            dfs(nex, o, labels);
            for (int i = 0; i < 26; ++i) {
                f[o][i] += f[nex][i];
            }
        }
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        g.resize(n);
        for (const auto &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        f.assign(n, vector<int>(26));
        dfs(0, -1, labels);
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(f[i][labels[i] - 'a']);
        }
        return ans;
    }
};
