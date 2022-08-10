class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int accSum = 0, accSumMin = 0;
        for (int num : nums) {
            accSum += num;
            accSumMin = min(accSumMin, accSum);
        }
        return -accSumMin + 1;
    }
};
