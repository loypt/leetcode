class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int N = A.size();
        int W = A[0].size();
        int ans = 0;
        vector<string> cur(N);
        for (int j = 0; j < W; ++j) {
            vector<string> cur2 = cur;
            for (int i = 0; i < N; ++i) {
                cur2[i] += A[i][j];
            }
            if (isSorted(cur2)) {
                cur = cur2;
            } else {
                ans++;
            }
        }

        return ans;
    }

    bool isSorted(vector<string>& A) {
        for (int i = 0; i < A.size() - 1; ++i) {
            if (A[i] > A[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
