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
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, columns;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }
        rows = matrix.size();
        columns = matrix[0].size();

        auto visited = vector<vector<int>> (rows, vector<int>(columns));
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                ans = max(ans , dfs(matrix, i, j, visited));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int row, int column, vector<vector<int>> &visited){
        if (visited[row][column] != 0){
            return visited[row][column];
        }
        ++visited[row][column];
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dirs[i][0], newColumn = column + dirs[i][1];
            if (newRow>=0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[row][column]){
                visited[row][column] = max(visited[row][column], dfs(matrix, newRow, newColumn, visited)+1);
            }
        }
        return visited[row][column];
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    Solution solution;
    cout << solution.longestIncreasingPath(matrix);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

