class Solution {
public:
    long long maxSpending(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<int> B(m * n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                B[i * n + j] = A[i][j];
        sort(B.begin(), B.end());
        long long res = 0, d = 1;
        for (int v: B)
            res += d++ * v;
        return res;
    }
};
