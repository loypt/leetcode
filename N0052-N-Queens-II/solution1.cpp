class Solution {
public:
    int totalNQueens(int n) {
        std::vector<int> flag(5 * n - 2, 1);
        return totalNQueens(flag, 0, n);
    }
private:
    int totalNQueens(std::vector<int> &flag, int row, int &n) {
        if (row == n)
            return 1;
        int res = 0;
        for (int col = 0; col != n; ++col)
            if (flag[col] && flag[col + row + n] && flag[col - row + 4 * n - 2]) {
                flag[col] = flag[col + row + n] = flag[col - row + 4 * n - 2] = 0;
                res += totalNQueens(flag, row + 1, n);
                flag[col] = flag[col + row + n] = flag[col - row + 4 * n - 2] = 1;
            }
		return res;
    }
};
