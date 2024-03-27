class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int n = ranges.size();
        long long res = 1;
        for (int i = 0; i < n; ) {
            int r = ranges[i][1];
            int j = i + 1;
            while (j < n && ranges[j][0] <= r) {
                r = max(r, ranges[j][1]);
                j++;
            }
            res = res * 2 % mod;
            i = j;
        }
        return res;
    }
};
