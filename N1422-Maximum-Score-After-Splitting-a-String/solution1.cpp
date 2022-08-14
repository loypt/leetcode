class Solution {
public:
    int maxScore(string s) {
        int cnt = count(s.begin(), s.end(), '1'), ans = 0;
        for_each(s.begin(), s.end() - 1, [&](char c){ans = max(ans, cnt += (c == '0' ? 1 : -1));});
        return ans;
    }
};
