//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/5/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
    int rows;
    int columns;
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        if (!rows) return 0;
        columns = grid[0].size();

        int islands = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < columns; ++c) {
                if (grid[r][c] == '1'){
                    ++islands;
                    dfs(grid, r, c);
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>>& grid, int row, int column){

        grid[row][column] = '0';
        if (row-1 >= 0 && grid[row-1][column] == '1') dfs(grid, row-1, column);
        if (row+1 < rows && grid[row+1][column] == '1') dfs(grid, row+1, column);
        if (column - 1 >= 0 && grid[row][column-1] == '1') dfs(grid, row, column-1);
        if (column + 1 < columns && grid[row][column+1] == '1') dfs(grid, row, column+1);
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                  {'1','1','0','0','0'},
                                  {'0','0','1','0','0'},
                                  {'0','0','0','1','1'}};
    Solution solution;
    cout << solution.numIslands(grid);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

