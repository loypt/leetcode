class Solution {
public:
    long long countOne(long long x) {
        long long res = 0;
        int sum = 0;

        for (int i = 60; i >= 0; i--) {
            if (1LL << i & x) {
                res += 1LL * sum * (1LL << i);
                sum += 1;
                
                if (i > 0) {
                    res += 1LL * i * (1LL << (i - 1));
                }
            }
        }
        res += sum;
        return res;
    }

    long long countPow(long long x) {
        long long res = 0;
        int sum = 0;

        for (int i = 60; i >= 0; i--) {
            if (1LL << i & x) {
                res += 1LL * sum * (1LL << i);
                sum += i;
                
                if (i > 0) {
                    res += 1LL * i * (i - 1) / 2 * (1LL << (i - 1));
                }
            }
        }
        res += sum;
        return res;
    }

    int pow_mod(long long x, long long y, int mod) {
        int res = 1;
        while (y) {
            if (y & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    }

    long long mid_check(long long x) {
        long long l = 1, r = 1e15;
        while (l < r) {
            long long mid = (l + r) >> 1;
            if (countOne(mid) >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            queries[i][0]++;
            queries[i][1]++;
            long long l = mid_check(queries[i][0]);
            long long r = mid_check(queries[i][1]);
            int mod = queries[i][2];

            long long res = 1;
            long long pre = countOne(l - 1);
            for (int j = 0; j < 60; j++) {
                if (1LL << j & l) {
                    pre++;
                    if (pre >= queries[i][0] && pre <= queries[i][1]) {
                        res = res * (1LL << j) % mod;
                    }
                }
            }

            if (r > l) {
                long long bac = countOne(r - 1);
                for (int j = 0; j < 60; j++) {
                    if (1LL << j & r) {
                        bac++;
                        if (bac >= queries[i][0] && bac <= queries[i][1]) {
                            res = res * (1LL << j) % mod;
                        }
                    }
                }
            }

            if (r - l > 1) {
                long long xs = countPow(r - 1) - countPow(l);
                res = res * pow_mod(2LL, xs, mod) % mod;
            }
            ans.push_back(res);
        }

        return ans;
    }
};
