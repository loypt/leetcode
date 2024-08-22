class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long l = 1, r = (k + 1) << x;
        while (l < r) {
            long long m = (l + r + 1) / 2;
            if (accumulatedPrice(x, m) > k) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        return l;
    }

    long long accumulatedBitPrice(int x, long long num) {
        long long period = 1LL << x;
        long long res = period / 2 * (num / period);
        if (num % period >= period / 2) {
            res += num % period - (period / 2 - 1);
        }
        return res;
    }

    long long accumulatedPrice(int x, long long num) {
        long long res = 0;
        int length = 64 - __builtin_clzll(num);
        for (int i = x; i <= length; i += x) {
            res += accumulatedBitPrice(i, num);
        }
        return res;
    }
};
