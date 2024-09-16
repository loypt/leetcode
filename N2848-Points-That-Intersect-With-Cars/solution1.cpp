class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int C = 0;
        for (const auto& interval: nums) {
            C = max(C, interval[1]);
        }

        vector<int> count(C + 1);
        for (const auto& interval: nums) {
            for (int i = interval[0]; i <= interval[1]; ++i) {
                ++count[i];
            }
        }

        int ans = 0;
        for (int i = 1; i <= C; ++i) {
            if (count[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
