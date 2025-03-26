class Solution {
public:
    int minimumSum(int n, int k) {
        if (n <= k / 2) {
            return arithmeticSeriesSum(1, 1, n);
        } else {
            return arithmeticSeriesSum(1, 1, k / 2) + arithmeticSeriesSum(k, 1, n - k / 2);
        }
    }

private:
    int arithmeticSeriesSum(int a1, int d, int n) {
        return (a1 + a1 + (n - 1) * d) * n / 2;
    }
};
