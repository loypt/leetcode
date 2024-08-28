class Solution {
public:
    static constexpr int inf = 0x3f3f3f3f;
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> d(n + 1, inf);
        unordered_map<char, int> occ_cnt;
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            int max_cnt = 0;
            occ_cnt.clear();
            for (int j = i; j >= 1; j--) {
                occ_cnt[s[j - 1]]++;
                max_cnt = max(max_cnt, occ_cnt[s[j - 1]]);
                if (max_cnt * occ_cnt.size() == (i - j + 1) && d[j - 1] != inf) {
                    d[i] = min(d[i], d[j - 1] + 1);
                }
            }
        }
        return d[n];
    }
};
