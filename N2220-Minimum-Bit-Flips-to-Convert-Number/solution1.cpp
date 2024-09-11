class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        int tmp = start ^ goal;
        while (tmp) {
            res += tmp & 1;
            tmp >>= 1;
        }
        return res;
    }
};
