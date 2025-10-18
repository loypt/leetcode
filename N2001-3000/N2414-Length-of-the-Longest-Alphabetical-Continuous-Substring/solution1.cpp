class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 1;
        int cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1] + 1) {
                cur++;
            } else {
                cur = 1;
            }
            res = max(res, cur);
        }
        return res;
    }
};
