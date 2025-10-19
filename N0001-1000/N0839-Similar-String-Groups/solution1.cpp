class Solution {
public:
    vector<int> f;

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    bool check(const string &a, const string &b, int len) {
        int num = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                num++;
                if (num > 2) {
                    return false;
                }
            }
        }
        return true;
    }

    int numSimilarGroups(vector<string> &strs) {
        int n = strs.size();
        int m = strs[0].length();
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int fi = find(i), fj = find(j);
                if (fi == fj) {
                    continue;
                }
                if (check(strs[i], strs[j], m)) {
                    f[fi] = fj;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] == i) {
                ret++;
            }
        }
        return ret;
    }
};
