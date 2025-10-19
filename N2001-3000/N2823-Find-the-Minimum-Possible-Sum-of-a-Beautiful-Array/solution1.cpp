class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        const int mod = 1e9 + 7;
        int m = target / 2;
        if (n <= m) {
            return (long long) (1 + n) * n / 2 % mod;
        }
        return ((long long) (1 + m) * m / 2 + 
                ((long long) target + target + (n - m) - 1) * (n - m) / 2) % mod;
    }
};
