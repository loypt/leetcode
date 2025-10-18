class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size(), m = indices.size();

        unordered_map<int, vector<int>> ops;
        for (int i = 0; i < m; ++i) {
            ops[indices[i]].push_back(i);
        }

        string ans;
        for (int i = 0; i < n;) {
            bool succeed = false;
            if (ops.count(i)) {
                for (int pt: ops[i]) {
                    if (s.substr(i, sources[pt].size()) == sources[pt]) {
                        succeed = true;
                        ans += targets[pt];
                        i += sources[pt].size();
                        break;
                    }
                }
            }
            if (!succeed) {
                ans += s[i];
                ++i;
            }
        }
        return ans;
    }
};
