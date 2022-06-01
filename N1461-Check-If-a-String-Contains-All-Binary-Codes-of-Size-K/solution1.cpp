class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (1 << k) + k - 1) {
            return false;
        }

        string_view sv(s);
        unordered_set<string_view> exists;
        for (int i = 0; i + k <= s.size(); ++i) {
            exists.insert(sv.substr(i, k));
        }
        return exists.size() == (1 << k);
    }
};
