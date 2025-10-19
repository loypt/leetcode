class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MODULO = 1000000007;
        int sumsLength = n * (n + 1) / 2;
        auto sums = vector <int> (sumsLength);
        int index = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                sums[index++] = sum;
            }
        }
        sort(sums.begin(), sums.end());
        int ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sums[i]) % MODULO;
        }
        return ans;
    }
};
