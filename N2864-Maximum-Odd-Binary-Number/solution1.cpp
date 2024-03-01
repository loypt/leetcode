class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt[2] = {0};
        for (char c : s) cnt[c - '0']++;
        cnt[1]--;

        string ans;
        for (int k = 1; k >= 0; k--) for (int i = 1; i <= cnt[k]; i++) ans.push_back(k + '0');
        ans.push_back('1');
        return ans;
    }
};
