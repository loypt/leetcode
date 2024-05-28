class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length(), i = 0, j;
        for (j = 0; j < n; ++j) {
            if ((maxCost -= abs(s[j] - t[j])) < 0)
                maxCost += abs(s[i] - t[i++]);
        }
        return j - i;
    }
};
