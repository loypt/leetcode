class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0, mid = n/2;
        for(int i = 0; i < n; i++){
            sum+= mat[i][i] + mat[i][n-i-1];
        }
        return sum - mat[mid][mid]*(n&1);
    }
};
