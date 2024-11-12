class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            int count[2] = {0};
            for (int j = i; j < n; ++j) {
                count[s[j] - '0']++;
                if (count[0] > k && count[1] > k) {
                    break;
                }
                res++;
            }
        }
        return res;
    }
};
