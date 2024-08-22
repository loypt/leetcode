class Solution {
public:
    long long minEnd(int n, int x) {
        int bitCount = 64 - __builtin_clz(n) - __builtin_clz(x);
        long long res = x;
        long long m = n - 1;
        int j = 0;
        for (int i = 0; i < bitCount; ++i) {
            if (((res >> i) & 1) == 0) {
                if ((m >> j) & 1) {
                    res |= (1LL << i);
                }
                j++;
            }
        }
        return res;
    }
};
