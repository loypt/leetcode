class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        
        int row = 0, column = m-1;
        while(row < n && column >= 0){
            int num = matrix[row][column];
            if(num == target){
                return true;
            }else if(num > target){
                column--;
            }else{
                row++;
            }
        }
        return false;
    }
};
