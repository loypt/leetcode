class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int cnt = 0;
        long long total = 0;
        int mn = INT_MAX;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                mn = min(mn, abs(matrix[i][j]));
                if (matrix[i][j] < 0){
                    ++cnt;
                }
                total += abs(matrix[i][j]);
            }
        }
        if (cnt % 2 == 0){
            return total;
        }
        else{
            return total - 2 * mn;
        }
    }
};
