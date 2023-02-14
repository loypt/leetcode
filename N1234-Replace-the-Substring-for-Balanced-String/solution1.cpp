class Solution {
public:
    int idx(const char& c) {
        return c - 'A';
    }

    int balancedString(string s) {
        vector<int> cnt(26);
        for (auto c : s) {
            cnt[idx(c)]++;
        }

        int partial = s.size() / 4;
        int res = s.size();
        auto check = [&]() {
            if (cnt[idx('Q')] > partial || cnt[idx('W')] > partial \
                || cnt[idx('E')] > partial || cnt[idx('R')] > partial) {
                return false;
            }
            return true;
        };

        if (check()) {
            return 0;
        }
        for (int l = 0, r = 0; l < s.size(); l++) {
            while (r < s.size() && !check()) {
                cnt[idx(s[r])]--;
                r++;
            }
            if (!check()) {
                break;
            }
            res = min(res, r - l);
            cnt[idx(s[l])]++;
        }
        return res;
    }
};
