//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/13/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int m = matrix.size(), n  = matrix[0].size();
        int low  = 0, high = m*n-1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            int x = matrix[mid/n][mid%n];
            if (x < target){
                low = mid + 1;
            }else if(x > target){
                high = mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<vector<int>> matrix = {
            {1,3,5,7},
            {10,11,16,20},
            {23,30,34,60}
    };
    int target = 3;
    Solution solution;
    cout << solution.searchMatrix(matrix, target);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

