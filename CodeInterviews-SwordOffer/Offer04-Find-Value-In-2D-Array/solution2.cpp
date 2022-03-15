class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; ++i){
            if(matrix[i][0] <= target){
                int left = 0, right = m-1, mid; 
                while(left <= right){
                    mid = (right - left) / 2 + left;
                    if(matrix[i][mid] == target){
                        return true;
                    }else if(matrix[i][mid] > target){
                        right = mid -1;
                    }else{
                        left = mid+1;
                    }
                }
            }else{
                break;
            }
        }
        return false;
    }
};
