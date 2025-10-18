class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        int mx = 0;
        int mn = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                int diff;
                if (s[i] == '(') {
                    diff = 1;
                }
                else {
                    diff = -1;
                }
                mx += diff;
                mn = max(mn + diff, (i + 1) % 2);
            }
            else {
                ++mx;
                mn = max(mn - 1, (i + 1) % 2);
            }
            if (mx < mn) {
                return false;
            }
        }
        return mn == 0;
    }
};
