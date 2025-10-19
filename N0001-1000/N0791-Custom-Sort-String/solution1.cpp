class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> val(26);
        for (int i = 0; i < order.size(); ++i) {
            val[order[i] - 'a'] = i + 1;
        }
        sort(s.begin(), s.end(), [&](char c0, char c1) {
            return val[c0 - 'a'] < val[c1 - 'a'];
        });
        return s;
    }
};
