class Solution {
public:
    int distributeCookies(vector<int> &cookies, int k) {
        int n = cookies.size();
        vector<int> sum(1 << n);
        for (int i = 0; i < n; i++)
            for (int j = 0, bit = 1 << i; j < bit; j++)
                sum[bit | j] = sum[j] + cookies[i];

        vector<int> f(sum);
        for (int i = 1; i < k; i++) {
            for (int j = (1 << n) - 1; j; j--) {
                for (int s = j; s; s = (s - 1) & j) {
                    f[j] = min(f[j], max(f[j ^ s], sum[s]));
                }
            }
        }
        return f.back();
    }
};
