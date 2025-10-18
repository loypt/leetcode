class Solution {
public:
    int countAsterisks(string s) {
        bool valid = true;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '|') {
                valid = !valid;
            } else if (c == '*' && valid) {
                res++;
            }
        }
        return res;
    }
};
