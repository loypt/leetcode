class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, len = colors.length();
        int ret = 0;
        while (i < len) {
            char ch = colors[i];
            int maxValue = 0;
            int sum = 0;

            while (i < len && colors[i] == ch) {
                maxValue = max(maxValue, neededTime[i]);
                sum += neededTime[i];
                i++;
            }
            ret += sum - maxValue;
        }
        return ret;
    }
};
