class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        int len = s.size();

        vector<int> chs[26];
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            cnt++;
            if (i + 1 == len || s[i] != s[i + 1]) {
                int ch = s[i] - 'a';
                chs[ch].push_back(cnt);
                cnt = 0;

                for (int j = chs[ch].size() - 1; j > 0; j--) {
                    if (chs[ch][j] > chs[ch][j - 1]) {
                        swap(chs[ch][j], chs[ch][j - 1]);
                    } else {
                        break;
                    }
                }

                if (chs[ch].size() > 3) {
                    chs[ch].pop_back();
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (chs[i].size() > 0 && chs[i][0] > 2) {
                ans = max(ans, chs[i][0] - 2);
            }
            if (chs[i].size() > 1 && chs[i][0] > 1) {
                ans = max(ans, min(chs[i][0] - 1, chs[i][1]));
            }
            if (chs[i].size() > 2) {
                ans = max(ans, chs[i][2]);
            }
        }

        return ans;
    }
};
