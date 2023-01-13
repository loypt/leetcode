class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> sCounts, targetCounts;
        int n = s.size(), m = target.size();
        for (int i = 0; i < m; i++) {
            targetCounts[target[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (targetCounts.count(s[i])) {
                sCounts[s[i]]++;
            }
        }
        int ans = INT_MAX;
        for (auto &[c, count] : targetCounts) {
            int totalCount = sCounts[c];
            ans = min(ans, totalCount / count);
            if (ans == 0) {
                return 0;
            }
        }
        return ans;
    }
};
