class Solution {
    map<int, vector<int>> mp;
    map<int, int> deg;
    vector<vector<int>> ans;

    void dfs(int sn) {
        vector<int> &e = mp[sn];
        while (!e.empty()) {
            int fn = e.back();
            e.pop_back();
            dfs(fn);
            ans.push_back(vector<int>{sn, fn});
        }
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for (auto &pair : pairs) {
            mp[pair[0]].push_back(pair[1]);
            deg[pair[0]]--; deg[pair[1]]++;
        }
        for (auto it = deg.begin(); it != deg.end(); it++) if (it->second == -1) dfs(it->first);
        if (ans.empty()) dfs(deg.begin()->first);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
