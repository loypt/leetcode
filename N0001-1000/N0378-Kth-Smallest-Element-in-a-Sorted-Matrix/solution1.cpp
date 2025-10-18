//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/1/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace std::chrono;

class Solution{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k){
        struct node {
            int val, x, y;
            node(int val, int x, int y) : val(val), x(x), y(y) {}
            bool operator > (const node& a) const {return this->val > a.val;}
        };
        priority_queue<node, vector<node>, greater<node>> my_que; //  Gradually increase, min_heap
        int len = matrix.size();
        for (int i = 0; i < len; ++i) {
            my_que.emplace(matrix[i][0], i, 0);
        }
        for (int i = 0; i < k - 1; ++i) {
            node now = my_que.top();
            my_que.pop();
            if (now.y != len-1){ // not the end of line
                my_que.emplace(matrix[now.x][now.y+1], now.x, now.y+1);
            }
        }
        return my_que.top().val;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int n, k;
    cin >> n;
    vector<int> matrix_line(n);
    vector<vector<int>> matrix(n, matrix_line);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    cin >> k;
    Solution solution;
    cout << solution.kthSmallest(matrix, k);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

