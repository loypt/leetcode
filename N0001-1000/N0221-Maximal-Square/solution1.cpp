class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }
        int rows = matrix.size(), columns = matrix[0].size();
        int maxS = 0;
        vector<vector<int>> dp(rows, vector<int>(columns));
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < columns; ++j){
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                    maxS = max(maxS, dp[i][j]);
                }
            }
        }
        int maxArea = maxS * maxS;
        return maxArea;
    }
};
