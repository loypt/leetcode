class Solution {
public:
    using ll = long long;
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1, r = 1ll * ranks[0] * cars * cars;
        auto check = [&](ll m) {
            ll cnt = 0;
            for (auto x : ranks) {
                cnt += sqrt(m / x);
            }
            return cnt >= cars;
        };
        while (l < r) {
            ll m = l + r >> 1;
            if (check(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
