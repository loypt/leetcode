class Solution {
public:
    int countBeautifulPairs(vector<int> &nums) {
        int res = 0, cnt[10]{};
        for (int x: nums) {
            for (int y = 1; y <= 9; y++) {
                if (gcd(x % 10, y) == 1) {
                    res += cnt[y];
                }
            }
            while (x >= 10) {
                x /= 10;
            }
            cnt[x]++;
        }
        return res;
    }
};
