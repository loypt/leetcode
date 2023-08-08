class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int positiveMax = 0, negativeMin = 0;
        int positiveSum = 0, negativeSum = 0;
        for (int num : nums) {
            positiveSum += num;
            positiveMax = max(positiveMax, positiveSum);
            positiveSum = max(0, positiveSum);
            negativeSum += num;
            negativeMin = min(negativeMin, negativeSum);
            negativeSum = min(0, negativeSum);
        }
        return max(positiveMax, -negativeMin);
    }
};
