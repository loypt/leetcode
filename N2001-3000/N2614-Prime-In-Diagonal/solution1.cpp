class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i][i])) {
                res = max(res, nums[i][i]);
            }
            if (isPrime(nums[i][n - i - 1])) {
                res = max(res, nums[i][n - i - 1]);
            }
        }
        return res;
    }

    bool isPrime(int num) {
        if (num == 1) {
            return false;
        }
        int factor = 2;
        while (factor * factor <= num) {
            if (num % factor == 0) {
                return false;
            }
            factor++;
        }
        return true;
    }
};
