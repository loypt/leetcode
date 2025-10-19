class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (m > bloomDay.size() / k) {
            return -1;
        }
        int low = INT_MAX, high = 0;
        int length = bloomDay.size();
        for (int i = 0; i < length; i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        while (low < high) {
            int days = (high - low) / 2 + low;
            if (canMake(bloomDay, days, m, k)) {
                high = days;
            } else {
                low = days + 1;
            }
        }
        return low;
    }

    bool canMake(vector<int>& bloomDay, int days, int m, int k) {
        int bouquets = 0;
        int flowers = 0;
        int length = bloomDay.size();
        for (int i = 0; i < length && bouquets < m; i++) {
            if (bloomDay[i] <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
};
