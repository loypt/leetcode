class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            char a = s1[i], b = s2[i];
            if (a == 'x' and b == 'y') {
                xy++;
            }
            if (a == 'y' and b == 'x') {
                yx++;
            }
        }
        if ((xy + yx) % 2 == 1) {
            return -1;
        }
        return xy / 2 + yx / 2 + xy % 2 + yx % 2;
    }
};
