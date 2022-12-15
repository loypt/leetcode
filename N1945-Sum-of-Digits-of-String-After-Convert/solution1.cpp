class Solution {
public:
    int getLucky(string s, int k) {
        string digits;
        for (char ch: s) {
            digits += to_string(ch - 'a' + 1);
        }

        for (int i = 1; i <= k && digits.size() > 1; ++i) {
            int sum = 0;
            for (char ch: digits) {
                sum += ch - '0';
            }
            digits = to_string(sum);
        }

        return stoi(digits);
    }
};
