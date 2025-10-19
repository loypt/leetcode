class Solution {
public:
    bool help(const string& s, int k, int mi, int ma) {
        unordered_set<int> st;
        int t = 0;
        for (int r = 0; r < s.size(); ++r) {
            t = t * 2 + (s[r] - '0');
            if (r >= k) {
                t -= (s[r - k] - '0') << k;
            }
            if (r >= k - 1 && t >= mi && t <= ma) {
                st.insert(t);
            }
        }
        return st.size() == ma - mi + 1;
    }

    bool queryString(string s, int n) {
        if (n == 1) {
            return s.find('1') != -1;
        }
        int k = 30;
        while ((1 << k) >= n) {
            --k;
        }
        if (s.size() < (1 << (k - 1)) + k - 1 || s.size() < n - (1 << k) + k + 1) {
            return false;
        }
        return help(s, k, 1 << (k - 1), (1 << k) - 1) && help(s, k + 1, 1 << k, n);
    }
};
