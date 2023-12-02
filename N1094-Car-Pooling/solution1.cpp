class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int to_max = 0;
        for (const auto& trip: trips) {
            to_max = max(to_max, trip[2]);
        }

        vector<int> diff(to_max + 1);
        for (const auto& trip: trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }

        int count = 0;
        for (int i = 0; i <= to_max; ++i) {
            count += diff[i];
            if (count > capacity) {
                return false;
            }
        }
        return true;
    }
};
