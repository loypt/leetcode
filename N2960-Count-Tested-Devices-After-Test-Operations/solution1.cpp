class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int need = 0;
        for (int i = 0; i < n; i++) {
            if (batteryPercentages[i] > 0) {
                need++;
                for (int j = i + 1; j < n; j++) {
                    batteryPercentages[j] = max(batteryPercentages[j] - 1, 0);
                }
            }
        }
        return need;
    }
};
