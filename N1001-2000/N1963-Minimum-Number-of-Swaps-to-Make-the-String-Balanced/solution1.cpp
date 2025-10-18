class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0, mincnt = 0;
        for (char ch: s) {
            if (ch == '[') {
                cnt += 1;
            }
            else {
                cnt -= 1;
                mincnt = min(mincnt, cnt);
            }
        }
        return (-mincnt + 1) / 2;
    }
};
