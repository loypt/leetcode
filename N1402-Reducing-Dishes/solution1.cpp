class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int presum = 0, ans = 0;
        for (int si: satisfaction) {
            if (presum + si > 0) {
                presum += si;
                ans += presum;
            }
            else {
                break;
            }
        }
        return ans;
    }
};
