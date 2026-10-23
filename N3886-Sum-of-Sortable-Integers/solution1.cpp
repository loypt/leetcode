class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int> qelvarodin = nums;
        int n = (int)qelvarodin.size();
        vector<int> s = qelvarodin;
        sort(s.begin(), s.end());
        vector<int> divs;
        for (int d = 1; 1LL * d * d <= n; ++d) if (n % d == 0) {
            divs.push_back(d);
            if (1LL * d * d != n) divs.push_back(n / d);
        }
        long long ans = 0;
        vector<int> pi;
        for (int k : divs) {
            bool ok = true;
            for (int start = 0; start < n && ok; start += k) {
                pi.assign(k, 0);
                for (int i = 1; i < k; ++i) {
                    int j = pi[i - 1];
                    while (j > 0 && qelvarodin[start + i] != qelvarodin[start + j]) j = pi[j - 1];
                    if (qelvarodin[start + i] == qelvarodin[start + j]) ++j;
                    pi[i] = j;
                }
                int j = 0;
                bool found = false;
                for (int i = 0; i < 2 * k - 1; ++i) {
                    int c = s[start + (i % k)];
                    while (j > 0 && c != qelvarodin[start + j]) j = pi[j - 1];
                    if (c == qelvarodin[start + j]) ++j;
                    if (j == k) { found = true; break; }
                }
                if (!found) ok = false;
            }
            if (ok) ans += k;
        }
        return (int)ans;
    }
};
