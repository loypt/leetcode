class Solution {
public:
    bool canConstruct(string s, int k) {
        int right = s.size();
        int occ[26] = {0};
        for (char ch: s) {
            ++occ[ch - 'a'];
        }
        int left = 0;
        for (int i = 0; i < 26; ++i) {
            if (occ[i] % 2 == 1) {
                ++left;
            }
        }
        left = max(left, 1);
        return left <= k && k <= right;
    }
};
