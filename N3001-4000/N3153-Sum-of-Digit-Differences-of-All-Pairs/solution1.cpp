class Solution {
public:
    long long sumDigitDifferences(vector<int>& A) {
        int n = A.size(), m = to_string(A[0]).length();
        vector<vector<int>> count(m, vector<int>(10));
        long long res = 1LL * n * (n - 1) / 2 * m;
        for (int a : A) {
            for (int i = 0; i < m; i++) {
                res -= count[i][a % 10]++;
                a /= 10;
            }
        }
        return res;
    }
};
