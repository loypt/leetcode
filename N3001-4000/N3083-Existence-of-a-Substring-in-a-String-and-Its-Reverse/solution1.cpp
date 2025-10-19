class Solution {
public:
    bool isSubstringPresent(string s) {
        for (int i = 0; i + 1 < s.size(); i++) {
            string substr = s.substr(i, 2);
            reverse(substr.begin(), substr.end());
            if (s.find(substr) != string::npos) {
                return true;
            }
        }
        return false;
    }
};
