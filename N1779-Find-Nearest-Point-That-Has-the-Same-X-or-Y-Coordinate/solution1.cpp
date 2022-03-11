//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/10/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int index = -1;
        for (int i = 0, smallest=INT_MAX; i < points.size(); ++i) {
            int dx = x - points[i][0], dy = y - points[i][1];
            if (dx*dy == 0 && abs(dy + dx) < smallest){
                smallest = abs(dx+dy);
                index = i;
            }
        }
        return index;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int x = 3, y = 4;
    vector<vector<int>> points = {{1, 2},{3, 1}, {2, 4}};
    Solution solution;
    cout<<  solution.nearestValidPoint(x, y, points);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


