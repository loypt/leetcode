class Solution {
public:
    string reformat(string s) {
        int sum_digit = 0;
        for (auto& c : s) {
            if (isdigit(c)) {
                sum_digit++;
            }
        }
        int sum_alpha = s.size() - sum_digit;
        if (abs(sum_digit - sum_alpha) > 1) {
            return "";
        }
        bool flag = sum_digit > sum_alpha;
        for (int i = 0, j = 1; i < s.size(); i += 2) {
            if (isdigit(s[i]) != flag) {
                while (isdigit(s[j]) != flag) {
                    j += 2;
                }
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};
