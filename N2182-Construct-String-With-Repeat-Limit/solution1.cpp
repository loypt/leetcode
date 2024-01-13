const int N = 26;
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(N);
        for (char c : s) {
            count[c - 'a']++;
        }
        string ret;
        int m = 0;
        for (int i = N - 1, j = N - 2; i >= 0 && j >= 0;) {
            if (count[i] == 0) {
                m = 0;
                i--;
            } else if (m < repeatLimit) {
                count[i]--;
                ret.push_back('a' + i);
                m++;
            } else if (j >= i || count[j] == 0) {
                j--;
            } else {
                count[j]--;
                ret.push_back('a' + j);
                m = 0;
            }
        }
        return ret;
    }
};
