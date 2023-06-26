class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        int startPos = locations[start];
        int finishPos = locations[finish];
        sort(locations.begin(), locations.end());
        for (int i = 0; i < n; ++i) {
            if (startPos == locations[i]) {
                start = i;
            }
            if (finishPos == locations[i]) {
                finish = i;
            }
        }

        vector<vector<int>> dpL(n, vector<int>(fuel + 1));
        vector<vector<int>> dpR(n, vector<int>(fuel + 1));
        dpL[start][0] = dpR[start][0] = 1;
        
        for (int used = 0; used <= fuel; ++used) {
            for (int city = n - 2; city >= 0; --city) {
                if (int delta = locations[city + 1] - locations[city]; used >= delta) {
                    dpL[city][used] = ((used == delta ? 0 : dpL[city + 1][used - delta]) * 2 % mod + dpR[city + 1][used - delta]) % mod;
                }
            }
            for (int city = 1; city < n; ++city) {
                if (int delta = locations[city] - locations[city - 1]; used >= delta) {
                    dpR[city][used] = ((used == delta ? 0 : dpR[city - 1][used - delta]) * 2 % mod + dpL[city - 1][used - delta]) % mod;
                }
            }
        }

        int ans = 0;
        for (int used = 0; used <= fuel; ++used) {
            ans += (dpL[finish][used] + dpR[finish][used]) % mod;
            ans %= mod;
        }
        if (start == finish) {
            ans = (ans + mod - 1) % mod;
        }
        return ans;
    }
};
