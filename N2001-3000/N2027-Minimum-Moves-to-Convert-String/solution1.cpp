class Solution {
public:
    int minimumMoves(string s) {
        int covered = -1, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'X' && i > covered) {
                res += 1;
                covered = i + 2;
            }
        }
        return res;
    }
};
