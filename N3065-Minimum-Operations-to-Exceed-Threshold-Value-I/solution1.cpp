class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        for (int num: nums) {
            if (num < k) {
                res++;
            }
        }
        return res;
    }
};
