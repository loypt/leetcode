class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int r = n-2; r >= 0; --r){
            for(int c = 0; c < n; ++c){
                int best = matrix[r+1][c];
                if(c > 0){
                    best = min(best, matrix[r+1][c-1]);
                }
                if(c+1 < n){
                    best = min(best, matrix[r+1][c+1]);
                }
                matrix[r][c] += best;
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};
