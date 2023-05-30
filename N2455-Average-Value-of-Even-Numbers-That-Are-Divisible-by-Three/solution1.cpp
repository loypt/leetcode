class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total = 0, k = 0;
        for (int a : nums) {
            if (a % 6 == 0) {
                total += a;
                k++;
            }
        }
        return k > 0 ? total / k : 0;
    }
};
