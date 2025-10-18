class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] > s[i + 1] && s[i] % 2 == s[i + 1] % 2) {
                swap(s[i], s[i + 1]);
                break;
            }
        }
        return s;
    }
};
