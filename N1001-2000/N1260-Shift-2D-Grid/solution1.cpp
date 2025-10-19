class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for(; k > 0; k--){
            int previous = grid[grid.size()-1][grid[0].size()-1];
            for(int row = 0; row < grid.size(); row++){
                for(int col = 0; col < grid[0].size(); col++){
                    int temp = grid[row][col];
                    grid[row][col] = previous;
                    previous = temp;
                }
            }
        }
        return grid;
    }
};
