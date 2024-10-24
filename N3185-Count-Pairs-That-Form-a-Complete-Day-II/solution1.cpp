class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        vector<int> cnt(24);
        for (int hour : hours) {
            ans += cnt[(24 - hour % 24) % 24];
            cnt[hour % 24]++;
        }
        return ans;
    }
};
