//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/4/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double v[101][101] = {0.0};
        v[0][0] = poured;

        for (int i = 0; i < query_row; ++i) {
            for (int j = 0; j <= i; ++j) {
                double q = (v[i][j] - 1.0 ) / 2.0;
                if (q > 0){
                    v[i+1][j] += q;
                    v[i+1][j+1] += q;
                }
            }
        }
        return min(1.0, v[query_row][query_glass]);
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int poured = 1, query_row = 1, query_glass = 1;
    Solution solution;
    cout << solution.champagneTower(poured, query_row, query_glass);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

