class Solution {
    unordered_set<string> powerOf2Digits;
public:
    bool reorderedPowerOf2(int n) {
        int init = [&]() {
            for (int n = 1; n <= 1e9; n <<= 1) {
                powerOf2Digits.insert(countDigits(n));
            }
            return 0;
        }();
        return powerOf2Digits.count(countDigits(n));
    }
    string countDigits(int n) {
        string cnt(10, 0);
        while (n) {
            ++cnt[n % 10];
            n /= 10;
        }
        return cnt;
    }
};
